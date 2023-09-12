/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:18:33 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/12 01:58:01 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_data	*data;

	if (ac < 5 || ac > 6 || check_args(av))
		return (printf("Error: wrong number of arguments\n"), 1);
	data = (t_data *)malloc(sizeof(t_data));
	philo = (t_philo *)malloc(sizeof(t_philo) * check_atoi(av[1]));
	if (!data || !philo)
		return (printf("Error: malloc failed\n"), 1);
	if (init_data(data, av))
		return (printf("Error: init data failed\n"), 1);
	if (init_philos_forks(philo, data))
		return (printf("Error: init philo failed\n"), 1);
	if (check_dead(philo))
	{
		if (detach_philos(philo, data))
			return (printf("Error: detach philos failed\n"), 1);
		return (1);
	}
	if (join_destroy(philo, data))
		return (printf("Error: join destroy failed\n"), 1);
	return (0);
}
