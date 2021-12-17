/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:14:18 by tcordonn          #+#    #+#             */
/*   Updated: 2021/12/17 09:05:39 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	end_threads_and_mutex(t_philos *p)
{
	int	i;

	i = -1;
	while (!trigger_end(p))
		usleep(1);
	pthread_mutex_destroy(&p->inf.write_mutex);
	pthread_mutex_destroy(&p->inf.death);
	pthread_mutex_destroy(&p->inf.time_to_eat);
	pthread_mutex_destroy(&p->inf.finish);
	while (++i < p->inf.philos)
		pthread_mutex_destroy(&p->ph[i].my_f);
	i = -1;
	while (++i < p->inf.philos)
	{
		//ft_putstr_fd("join\n", 1);
		pthread_join(p->ph[i].thread_id, NULL);
	}
	if (p->inf.stop == 2)
		printf("Each philosopher ate %ld time(s)\n", p->inf.meals);
	free(p->ph);
	return (0);
}

int	any_death(t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->inf->death);
	if (i > 0)
		ph->inf->stop = i;
	if (ph->inf->stop > 0)
	{
		pthread_mutex_unlock(&ph->inf->death);
		return (1);
	}
	pthread_mutex_unlock(&ph->inf->death);
	return (0);
}

void	*supervisor(void	*data)
{
	t_philo		*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->inf->die + 1, ph);
	pthread_mutex_lock(&ph->inf->time_to_eat);
	pthread_mutex_lock(&ph->inf->finish);
	if (!any_death(ph, 0) && !ph->finish && ((ft_get_time() - ph->eat_t) \
		>= (long)(ph->inf->die)))
	{
		pthread_mutex_unlock(&ph->inf->time_to_eat);
		pthread_mutex_unlock(&ph->inf->finish);
		pthread_mutex_lock(&ph->inf->write_mutex);
		write_status("died\n", ph);
		pthread_mutex_unlock(&ph->inf->write_mutex);
		any_death(ph, 1);
	}
	pthread_mutex_unlock(&ph->inf->time_to_eat);
	pthread_mutex_unlock(&ph->inf->finish);
	return (NULL);
}

void	*thread(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(100, ph);
	while (!any_death(ph, 0))
	{
		pthread_create(&ph->thread_death_id, NULL, supervisor, data);
		routine(ph);
		pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_eat == ph->inf->meals)
		{
			pthread_mutex_lock(&ph->inf->finish);
			ph->finish = 1;
			ph->inf->ph_finish++;
			if (ph->inf->ph_finish == ph->inf->philos)
			{
				pthread_mutex_unlock(&ph->inf->finish);
				any_death(ph, 2);
			}
			pthread_mutex_unlock(&ph->inf->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	start_threads(t_philos *p)
{
	int	i;

	i = 0;
	while (i < p->inf.philos)
	{
		p->ph[i].inf = &p->inf;
		if (pthread_create(&p->ph[i].thread_id, NULL, thread, &p->ph[i]) != 0)
			return (write_error("Pthread error\n"));
		i++;
	}
	return (1);
}
