/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:19:15 by olahmami          #+#    #+#             */
/*   Updated: 2023/08/31 17:05:56 by olahmami         ###   ########.fr       */
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

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_t_eat;
	pthread_mutex_t		*forks;
	long				start_time;
	t_philo				*philos;
}						t_data;
typedef struct s_philo
{
	pthread_t			threads;
	int					id;
	t_data				*data;
}						t_philo;

int						ft_isdigit(int c);
int						check_atoi(char *str);
int						check_args(char **av);

void					*to_do(void *arg);
long					current_time_in_milliseconds(void);

#endif