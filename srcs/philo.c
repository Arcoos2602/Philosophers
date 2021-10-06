/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:14:18 by tcordonn          #+#    #+#             */
/*   Updated: 2021/10/06 13:15:10 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *arg)
{
	t_philo philo;

	philo = *((t_philo *) arg);
	//think();
	//eat();
	//sleep;
	// if life call to routine
	// if num of meals
	return (NULL);
}

void	init(t_philo *philos, char **argv)
{
	philos->info->time_to_die = ft_atoi(argv[2]) * 1000;
	philos->info->time_to_eat = ft_atoi(argv[3]) * 1000;
	philos->info->time_to_think = ft_atoi(argv[4]) * 1000;
	philos->finish = -1;
	if (argv[5] != NULL)
		philos->info->meals = ft_atoi(argv[5]);
	else
		philos->info->meals = -1;
	pthread_create(&philos->thread_id, NULL, routine, philos);
}

int	main(int argc, char **argv)
{
	t_philo		philos[ft_atoi(argv[1])];
	int			num_of_threads;
	int			i;

	i = -1;
	(void)argc;
	/*if (argc > 5 || argc < 4)
		return (-1);*/
	num_of_threads = ft_atoi(argv[2]);
	printf("Before_threads\n");
	while (i++ < num_of_threads)
		init(&philos[i], argv);
	i = -1;
	while (i++ < num_of_threads)
		pthread_join(philos[i].thread_id, NULL);
	printf("After Threads\n");
	return (0);
}
