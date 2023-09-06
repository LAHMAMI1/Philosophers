/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 23:37:55 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/06 01:51:40 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_data(t_data *data, char **av)
{
	data->num_philo = check_atoi(av[1]);
	data->time_to_die = check_atoi(av[2]);
	data->time_to_eat = check_atoi(av[3]);
	data->time_to_sleep = check_atoi(av[4]);
	data->num_time_eat = -1;
	if (av[5])
		data->num_time_eat = check_atoi(av[5]);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (1);
	data->start_time = current_time();
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	if (pthread_mutex_init(&data->dead, NULL))
		return (1);
	return (0);
}

int init_philos_forks(t_philo *philo, t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].last_eat = current_time();
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	// i = 0;
	// while (i < data->num_philo)
	// {
	// 	if (pthread_create(&philo[i].threads, NULL, &to_do, &philo[i]))
	// 		return (1);
	// 	i += 2;
	// }
	// usleep(1000);
	// i = 1;
	// while (i < data->num_philo)
	// {
	// 	if (pthread_create(&philo[i].threads, NULL, &to_do, &philo[i]))
	// 		return (1);
	// 	i += 2;
	// }
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&philo[i].threads, NULL, &to_do, &philo[i]))
			return (1);
		i ++;
	}
	return (0);
}
