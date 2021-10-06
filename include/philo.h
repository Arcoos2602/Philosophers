/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcordonn <tcordonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:14:15 by tcordonn          #+#    #+#             */
/*   Updated: 2021/10/06 13:05:26 by tcordonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/includes/libft.h"

typedef struct 		s_info
{
	long			time_to_die;
	long			time_to_think;
	long			time_to_eat;
	long			meals;
}					t_info;

typedef struct 		s_philo
{
	struct timeval	time;
	int				life;
	int				num;
	int				finish;
	t_info			*info;
	pthread_t		thread_id;
}					t_philo;

#endif