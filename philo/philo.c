/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:18:33 by olahmami          #+#    #+#             */
/*   Updated: 2023/08/31 17:07:56 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(int ac, char **av, t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data || !data->forks)
		return (NULL);
	data->num_philo = check_atoi(av[1]);
	data->time_to_die = check_atoi(av[2]);
	data->time_to_eat = check_atoi(av[3]);
	data->time_to_sleep = check_atoi(av[4]);
	data->num_t_eat = -1;
	if (ac == 6)
		data->num_t_eat = check_atoi(av[5]);
	data->start_time = current_time_in_milliseconds();
}

int	main(int ac, char **av)
{
	t_philo *philo;
	t_data *data;
	int i;
	int j;

	if (ac < 5 || ac > 6 || check_args(av))
		return (printf("Error: wrong number of arguments\n"));
	init_philo(ac, av, data);
	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	if (!philo)
		return (1);
	i = 0;
	while (i < data->num_philo)
	{
		j = 1;
		philo[i].id = j;
		philo[i].data = data;
		pthread_create(&philo[i].threads, NULL, to_do, &philo[i]);
		j++;
		i++;
	}
	return (0);
}