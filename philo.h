/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:19:15 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/12 01:58:09 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				num_time_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	c_eat;
	unsigned long	start_time;
}					t_data;
typedef struct s_philo
{
	t_data			*data;
	int				id;
	pthread_t		threads;
	unsigned long	last_eat;
	int				count_meals;
	int				count;
	int				check_dead;
}					t_philo;

int					ft_isdigit(int c);
int					check_atoi(char *str);
int					check_args(char **av);
int					init_data(t_data *data, char **av);
unsigned long		current_time(void);
int					init_philos_forks(t_philo *philo, t_data *data);
void				eat(t_philo *philo);
void				sleep_think(t_philo *philo);
void				*to_do(void *arg);
void				print_msg(char *str, t_philo *philo);
void				my_sleep(long time);
int					check_dead(t_philo *philo);
int					detach_philos(t_philo *philo, t_data *data);
int					join_destroy(t_philo *philo, t_data *data);

#endif