/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:57:16 by thomas            #+#    #+#             */
/*   Updated: 2021/12/16 19:57:10 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	write_error(char *str)
{
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(str, 2);
	return (0);
}

int	check_death2(t_philos *ph)
{
	pthread_mutex_lock(&ph->inf.dead);
	if (ph->inf.stop)
	{
		pthread_mutex_unlock(&ph->inf.dead);
		return (1);
	}
	pthread_mutex_unlock(&ph->inf.dead);
	return (0);
}

void	stop(t_philos *p)
{
	int	i;

	i = -1;
	while (!check_death2(p))
		ft_usleep(1);
	while (++i < p->inf.philos)
		pthread_join(p->ph[i].thread_id, NULL);
	pthread_mutex_destroy(&p->inf.write_mutex);
	i = -1;
	while (++i < p->inf.philos)
		pthread_mutex_destroy(&p->ph[i].my_f);
	if (p->inf.stop == 2)
		printf("Each philosopher ate %ld time(s)\n", p->inf.meals);
	free(p->ph);
}

int	main(int argc, char **argv)
{
	t_philos p;
	
	if (!parse(argc, argv, &p))
		return (1);
	p.ph = malloc(sizeof(t_philo) * p.inf.philos);
	if (!p.ph)
	{
		ft_putstr_fd("Error : Malloc returned NULL\n", 2);
		return (1);
	}
	if (!initialize(&p) || !start_threads(&p))
	{
		free(p.ph);
		return (0);
	}
	stop(&p);
	return (0);
}
