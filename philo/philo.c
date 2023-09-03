/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:18:33 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/03 02:49:42 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_data(int ac, char **av, t_data *data)
{
	data->num_philo = check_atoi(av[1]);
	data->time_to_die = check_atoi(av[2]);
	data->time_to_eat = check_atoi(av[3]);
	data->time_to_sleep = check_atoi(av[4]);
	data->num_time_eat = -1;
	if (ac == 6)
		data->num_time_eat = check_atoi(av[5]);
	data->start_time = current_time_in_milliseconds();
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_philo);
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (!data->forks || !data->philos)
		return (1);
	return (0);
}

int init_philo_fork(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		if (pthread_create(&data->philos[i].threads, NULL, to_do, &data->philos[i]))
			return (1);
		if(pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	// t_philo *philo;
	t_data *data;

	if (ac < 5 || ac > 6 || check_args(av))
		return (printf("Error: wrong number of arguments\n"));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (init_data(ac, av, data))
		return (1);
	if (init_philo_fork(data))
		return (1);
	int i;
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philos[i].threads, NULL);
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_destroy(&data->forks[i]))
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&data->print))
		return (1);
	// printf("num_philo: %d\n", data->num_philo);
	return (0);
}