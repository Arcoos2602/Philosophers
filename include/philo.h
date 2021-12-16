/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomas <thomas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:14:15 by tcordonn          #+#    #+#             */
/*   Updated: 2021/12/16 20:00:31 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct 		s_info
{
	long int				philos;
	long int				die;
	long int				sleep;
	long int				eat;
	long int				meals;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						ph_finish; // nb de ph finit
	int						stop;
}					t_info;

typedef struct 		s_philo
{
	int	id;
	pthread_t		thread_id;
	pthread_t		thread_death_id; // id du thread qui check la mort pour la perf
	pthread_mutex_t			*next_f; // pointeur sur la fourchette du voisin philo
	pthread_mutex_t			my_f; // fourchette du philo
	t_info					*inf; // pointeur sur info
	long int				eat_t; // temps qu'il a pris pour manger pour le check ensuite
	unsigned int			nb_eat; // nombre de fois où le philo a mangé
	int						finish; // 0 ou 1
}					t_philo;

typedef struct s_philos // liste chaînée de philos
{
	t_philo		*ph;
	t_info		inf;
}				t_philos;

int		parse(int argc, char **argv, t_philos *p);
void	ft_putstr_fd(char *str, int fd);
long int actual_time(void);
int		write_error(char *str);
int		initialize(t_philos *ph);
int		start_threads(t_philos *ph);
void	ft_usleep(long int time_in_ms);
int		check_death(t_philo *ph, int i);
void	write_status(char *str, t_philo *ph);
void	routine(t_philo *ph);

#endif