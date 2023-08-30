/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:18:33 by olahmami          #+#    #+#             */
/*   Updated: 2023/08/30 03:51:52 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(int ac, char **av, t_philo *philo)
{
	if (ac < 5 || ac > 6 || check_args(av))
		return (printf("Error: wrong number of arguments\n"));
	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->num_philo);
	if (!philo || !philo->forks)
		return (1);
	philo->num_philo = check_atoi(av[1]);
	philo->time_to_die = check_atoi(av[2]);
	philo->time_to_eat = check_atoi(av[3]);
	philo->time_to_sleep = check_atoi(av[4]);
	philo->num_eat = -1;
	if (ac == 6)
		philo->num_eat = check_atoi(av[5]);
	philo->start_time = current_time_in_milliseconds();
}

int	main(int ac, char **av)
{
	t_philo *philo;

	init_philo(ac, av, philo);
	while (philo->num_philo > 0)
	{
		pthread_create(philo->threads, NULL, &to_do, philo);
		pthread_mutex_init(&philo->forks[philo->num_philo], NULL);
		philo->num_philo--;
	}
	return (0);
}