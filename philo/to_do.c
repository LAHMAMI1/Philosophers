/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:21:14 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/03 23:20:28 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_msg(char *str, t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ms %d %s\n", current_time_in_milliseconds() - philo->data->start_time, philo->id, str);
	pthread_mutex_unlock(&philo->data->print);
}

void my_sleep(long time)
{
	long start_time;
	long end_time;

	start_time = current_time_in_milliseconds();
	usleep(time * 1000);
	end_time = current_time_in_milliseconds();
	if(end_time - start_time < time)
		usleep((time - (end_time - start_time)) * 1000);
}

int  check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead);
	if (current_time_in_milliseconds() - philo->last_eat > philo->data->time_to_die)
	{
		print_msg("died", philo);
		pthread_mutex_unlock(&philo->data->dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead);
	return (0);
}

void *to_do(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		print_msg("has taken a left fork", philo);
		pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->num_philo]);
		print_msg("has taken a right fork", philo);
		print_msg("is eating", philo);
		my_sleep(philo->data->time_to_eat);
		pthread_mutex_lock(&philo->data->dead);
		philo->last_eat = current_time_in_milliseconds();
		pthread_mutex_unlock(&philo->data->dead);
		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->num_philo]);
		print_msg("is sleeping", philo);
		my_sleep(philo->data->time_to_sleep);
		print_msg("is thinking", philo);
		if (check_death(philo))
			break ;
	}
	return (NULL);
}