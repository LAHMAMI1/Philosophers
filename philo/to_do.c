/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:21:14 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/08 15:57:46 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	print_msg("is eating", philo);
	pthread_mutex_lock(&philo->data->dead);
	philo->last_eat = current_time();
	pthread_mutex_unlock(&philo->data->dead);
	pthread_mutex_lock(&philo->data->c_eat);
	philo->count_meals++;
	pthread_mutex_unlock(&philo->data->c_eat);
}

void	sleep_think(t_philo *philo)
{
	print_msg("is sleeping", philo);
	my_sleep(philo->data->time_to_sleep);
	print_msg("is thinking", philo);
}

void	*to_do(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->count_meals != philo->data->num_time_eat)
	{
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		print_msg("has taken a left fork", philo);
		pthread_mutex_lock(&philo->data->forks[philo->id
			% philo->data->num_philo]);
		print_msg("has taken a right fork", philo);
		eat(philo);
		my_sleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->data->forks[philo->id
			% philo->data->num_philo]);
		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		sleep_think(philo);
	}
	return (NULL);
}
