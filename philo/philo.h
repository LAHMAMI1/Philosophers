/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:19:15 by olahmami          #+#    #+#             */
/*   Updated: 2023/08/30 03:25:03 by olahmami         ###   ########.fr       */
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

typedef struct s_philo
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_eat;
	pthread_t		threads;
	pthread_mutex_t	*forks;
	long			start_time;
}					t_philo;

int					ft_isdigit(int c);
int					check_atoi(char *str);
int					check_args(char **av);

void				*to_do(void *arg);
long current_time_in_milliseconds();

#endif