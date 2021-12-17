/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:14:17 by thomas            #+#    #+#             */
/*   Updated: 2021/12/17 08:44:43 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	write_error(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	trigger_end(t_philos *ph)
{
	pthread_mutex_lock(&ph->inf.death);
	if (ph->inf.stop)
	{
		pthread_mutex_unlock(&ph->inf.death);
		return (1);
	}
	pthread_mutex_unlock(&ph->inf.death);
	return (0);
}

long int	ft_get_time(void)
{
	long int			time;
	struct timeval		current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		write_error("Gettimeofday error\n");
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int ms)
{
	long int	start_time;

	start_time = ft_get_time();
	while ((ft_get_time() - start_time) < ms)
		usleep(ms / 10);
}
