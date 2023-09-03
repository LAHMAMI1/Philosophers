/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:21:14 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/03 04:29:25 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *to_do(void *arg)
{
	t_philo *philo;
	// long current_time;

	philo = (t_philo *)arg;
	// current_time = current_time_in_milliseconds() - philo->data->start_time;
	while (1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_lock(&philo->data->print);
		printf("%ld ms %d has taken a left fork\n", current_time_in_milliseconds() - philo->data->start_time,philo->id);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->num_philo]);
		pthread_mutex_lock(&philo->data->print);
		printf("%ld ms %d has taken a right fork\n", current_time_in_milliseconds() - philo->data->start_time,philo->id);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->print);
		printf("%ld ms %d is eating\n", current_time_in_milliseconds() - philo->data->start_time,philo->id);
		pthread_mutex_unlock(&philo->data->print);
		while (current_time_in_milliseconds() - philo->data->start_time < philo->data->time_to_eat)
			usleep(1000);
		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->num_philo]);
		pthread_mutex_lock(&philo->data->print);
		printf("%ld ms %d is sleeping\n", current_time_in_milliseconds() - philo->data->start_time,philo->id);
		pthread_mutex_unlock(&philo->data->print);
		while (current_time_in_milliseconds() - philo->data->start_time < philo->data->time_to_sleep)
			usleep(1000);
		pthread_mutex_lock(&philo->data->print);
		printf("%ld ms %d is thinking\n", current_time_in_milliseconds() - philo->data->start_time,philo->id);
		pthread_mutex_unlock(&philo->data->print);
		pthread_mutex_lock(&philo->data->print);
		printf("%ld ms %d died\n", current_time_in_milliseconds() - philo->data->start_time,philo->id);
		pthread_mutex_unlock(&philo->data->print);
	}
	
	return (NULL);
}