/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 02:11:11 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/06 02:15:32 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long current_time()
{
	struct timeval current_time;
	unsigned long milliseconds;
	
	gettimeofday(&current_time, NULL);
	milliseconds = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (milliseconds);
}

void	print_msg(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ms %d %s\n", current_time()
			- philo->data->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	my_sleep(long time)
{
	long	start_time;
	long	end_time;

	start_time = current_time();
	usleep(time * 1000);
	end_time = current_time();
	if (end_time - start_time < time)
		usleep((time - (end_time - start_time)) * 1000);
}

int check_dead(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->num_philo)
	{
		pthread_mutex_lock(&philo->data->dead);
		if (current_time() - philo[i].last_eat > philo->data->time_to_die)
		{
			print_msg("died", &philo[i]);
			pthread_mutex_unlock(&philo->data->dead);
			return (1);
		}
		i++;
		if (i == philo->data->num_philo)
			i = 0;
		pthread_mutex_unlock(&philo->data->dead);
	}
	return (0);
}