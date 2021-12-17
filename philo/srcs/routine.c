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
	time = actual_time() - ph->inf->start_t;
	if (time >= 0 && time <= 2147483647 && !check_death(ph, 0)) // comprendre
	{
		printf("%ld ", time);
		printf("%d %s", ph->id, str);
	}
}

void	sleep_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->inf->write_mutex);
	ft_usleep(ph->inf->sleep);
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->inf->write_mutex);
}

void	routine(t_philo *ph)
{
	pthread_mutex_lock(&ph->my_f);
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->inf->write_mutex);
	if (!ph->next_f)
	{
		ft_usleep(ph->inf->die);
		//check_death(ph, 1);
		return ;
	}
	pthread_mutex_lock(ph->next_f);
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->inf->write_mutex);
	pthread_mutex_lock(&ph->inf->write_mutex);
	write_status("is eating\n", ph);
	pthread_mutex_lock(&ph->inf->time_eat);
	ph->eat_t = actual_time();
	pthread_mutex_unlock(&ph->inf->time_eat);
	pthread_mutex_unlock(&ph->inf->write_mutex);
	ft_usleep(ph->inf->eat);
	pthread_mutex_unlock(ph->next_f);
	pthread_mutex_unlock(&ph->my_f);
	sleep_think(ph);
}