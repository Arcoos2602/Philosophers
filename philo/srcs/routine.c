/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:40:47 by thomas            #+#    #+#             */
/*   Updated: 2021/12/17 09:35:06 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	write_status(char *str, t_philo *ph)
{
	long int		time;

	time = -1;
	time = ft_get_time() - ph->inf->start_t;
	if (time >= 0 && time <= 2147483647 && !any_death(ph, 0))
	{
		printf("%ld ", time);
		printf("%d %s", ph->id, str);
	}
}

void	meditation(t_philo *ph)
{
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->inf->write_mutex);
	ft_usleep(ph->inf->sleep, ph);
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->inf->write_mutex);
}

void	eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("is eating\n", ph);
	pthread_mutex_lock(&ph->inf->time_to_eat);
	ph->eat_t = ft_get_time();
	pthread_mutex_unlock(&ph->inf->time_to_eat);
	pthread_mutex_unlock(&ph->inf->write_mutex);
	ft_usleep(ph->inf->eat, ph);
	pthread_mutex_unlock(ph->next_f);
	pthread_mutex_unlock(&ph->my_f);
}

void	routine(t_philo *ph)
{
	pthread_mutex_lock(&ph->my_f);
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->inf->write_mutex);
	if (!ph->next_f)
		return ;
	pthread_mutex_lock(ph->next_f);
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->inf->write_mutex);
	eat(ph);
	meditation(ph);
}
