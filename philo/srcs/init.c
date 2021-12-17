/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:20:17 by thomas            #+#    #+#             */
/*   Updated: 2021/12/16 21:02:16 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	numeric(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] != '-' && (argv[i][j] < '0' || argv[i][j] > '9'))
				return (write_error("Non numeric argument\n"));
		}
	}
	return (1);
}

int	check_limits(t_philos *p, int argc)
{
	long int	m;

	m = 2147483647;
	if (p->inf.philos <= 0 || p->inf.die <= 0 || p->inf.eat <= 0 \
			|| p->inf.sleep <= 0 || (argc == 6 && p->inf.meals < 0))
		return (write_error("Lower or equal to 0 argument(s)\n"));
	if (p->inf.philos > m || p->inf.die > m || p->inf.eat > m \
			|| p->inf.sleep > m || p->inf.meals > m)
		return (write_error("Bigger than int max argument(s)\n"));
	m = -2147483648;
	if (p->inf.philos < m || p->inf.die < m || p->inf.eat < m \
			|| p->inf.sleep < m || (argc == 6 && p->inf.meals < m))
		return (write_error("Lower than int min argument(s)\n"));
	return (1);
}

int	parse(int argc, char **argv, t_philos *p)
{
	if ((argc == 5 || argc == 6) && numeric(argv))
	{
		p->inf.philos = ft_atol(argv[1]);
		p->inf.die = ft_atol(argv[2]);
		p->inf.eat = ft_atol(argv[3]);
		p->inf.sleep = ft_atol(argv[4]);
		p->inf.meals = -1;
		if (argc > 5)
			p->inf.meals = ft_atol(argv[5]);
		if (!check_limits(p, argc))
			return (0);
		return (1);
	}
	return (write_error("Minimum of arguments is 4\n"));
}

void	init_mutex(t_philos *p)
{
	pthread_mutex_init(&p->inf.write_mutex, NULL);
	pthread_mutex_init(&p->inf.death, NULL);
	pthread_mutex_init(&p->inf.time_to_eat, NULL);
	pthread_mutex_init(&p->inf.finish, NULL);
}

int	initialize(t_philos *p)
{
	int	i;

	i = -1;
	p->inf.start_t = ft_get_time();
	p->inf.stop = 0;
	p->inf.ph_finish = 0;
	init_mutex(p);
	while (++i < p->inf.philos)
	{
		p->ph[i].id = i + 1;
		p->ph[i].eat_t = p->inf.start_t;
		p->ph[i].nb_eat = 0;
		p->ph[i].finish = 0;
		p->ph[i].next_f = NULL;
		pthread_mutex_init(&p->ph[i].my_f, NULL);
		if (p->inf.philos == 1)
			return (1);
		if (p->inf.philos - 1 == i)
			p->ph[i].next_f = &p->ph[0].my_f;
		else
			p->ph[i].next_f = &p->ph[i + 1].my_f;
	}
	return (1);
}
