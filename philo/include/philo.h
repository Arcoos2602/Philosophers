/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:14:15 by tcordonn          #+#    #+#             */
/*   Updated: 2021/12/17 09:31:08 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	long int				philos;
	long int				die;
	long int				sleep;
	long int				eat;
	long int				meals;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			death;
	pthread_mutex_t			time_to_eat;
	pthread_mutex_t			finish;
	int						ph_finish;
	int						stop;
}					t_info;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*next_f;
	pthread_mutex_t			my_f;
	t_info					*inf;
	long int				eat_t;
	unsigned int			nb_eat;
	int						finish;
}					t_philo;

typedef struct s_philos
{
	t_philo		*ph;
	t_info		inf;
}				t_philos;

int		parse(int argc, char **argv, t_philos *p);
void	ft_putstr_fd(char *str, int fd);
long	int	ft_atol(const char *nptr);
long	int	ft_get_time(void);
int		write_error(char *str);
int		initialize(t_philos *ph);
int		start_threads(t_philos *ph);
void	ft_usleep(long int time_in_ms, t_philo *ph);
int		any_death(t_philo *ph, int i);
int		write_error(char *str);
void	write_status(char *str, t_philo *ph);
void	routine(t_philo *ph);
int		trigger_end(t_philos *ph);
int		end_threads_and_mutex(t_philos *p);

#endif