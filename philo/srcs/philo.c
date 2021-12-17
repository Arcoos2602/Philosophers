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

int	check_death(t_philo *ph, int i)
{
	pthread_mutex_lock(&ph->inf->dead);
	if (i > 0)
		ph->inf->stop = i;
	if (ph->inf->stop)
	{
		pthread_mutex_unlock(&ph->inf->dead);
		return (1);
	}
	pthread_mutex_unlock(&ph->inf->dead);
	return (0);
}

void	*is_dead(void	*data)
{
	t_philo		*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->inf->die + 1);
	pthread_mutex_lock(&ph->inf->time_eat);
	pthread_mutex_lock(&ph->inf->finish);
	if (!check_death(ph, 0) && !ph->finish && ((actual_time() - ph->eat_t) \
		>= (long)(ph->inf->die)))
	{
		pthread_mutex_unlock(&ph->inf->time_eat);
		pthread_mutex_unlock(&ph->inf->finish);
		pthread_mutex_lock(&ph->inf->write_mutex);
		write_status("died\n", ph);
		pthread_mutex_unlock(&ph->inf->write_mutex);
		check_death(ph, 1);
	}
	pthread_mutex_unlock(&ph->inf->time_eat);
	pthread_mutex_unlock(&ph->inf->finish);
	return (NULL);
}

void	*thread(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->inf->eat / 10);
	while (!check_death(ph, 0))
	{
		pthread_create(&ph->thread_death_id, NULL, is_dead, data);
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
				check_death(ph, 2);
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