/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:18:33 by olahmami          #+#    #+#             */
/*   Updated: 2023/08/29 01:01:55 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo *philo;
	pthread_t *threads;

	if (ac < 5 || ac > 6 || check_args(av))
		return (printf("Error: wrong number of arguments\n"));
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	philo->num_philo = check_atoi(av[1]);
	philo->time_to_die = check_atoi(av[2]);
	philo->time_to_eat = check_atoi(av[3]);
	philo->time_to_sleep = check_atoi(av[4]);
	philo->num_eat = -1;
	if (ac == 6)
		philo->num_eat = check_atoi(av[5]);
	// while (philo->num_philo > 0)
	// {
	// 	pthread_create(&threads[philo->num_philo], NULL, &function, NULL);
	// 	philo->num_philo--;
	// }
	
	
	return (0);
}