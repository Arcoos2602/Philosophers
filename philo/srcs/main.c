/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:57:16 by thomas            #+#    #+#             */
/*   Updated: 2021/12/17 08:46:42 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_philos	p;

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
	return (end_threads_and_mutex(&p));
}
