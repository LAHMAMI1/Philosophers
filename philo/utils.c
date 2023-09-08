/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 02:11:11 by olahmami          #+#    #+#             */
/*   Updated: 2023/09/08 16:35:17 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	current_time(void)
{
	struct timeval	current_time;
	unsigned long	milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (milliseconds);
}

void	print_msg(char *str, t_philo *philo)
{
	
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ms %d %s\n", current_time() - philo->data->start_time,
		philo->id, str);
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

int	check_meals(t_philo *philo)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock(&philo->data->c_eat);
	while (i < philo->data->num_philo)
	{
		if (philo->data->num_time_eat != -1
			&& philo[i].count_meals == philo->data->num_time_eat)
			count++;
		i++;
	}
	if (count == philo->data->num_philo)
	{
		pthread_mutex_unlock(&philo->data->c_eat);
			return (1);
	}
		
	pthread_mutex_unlock(&philo->data->c_eat);
	return (0);
}

int	check_dead(t_philo *philo)
{
	int	i;

	while (philo->check_dead == 0)
	{
		i = 0;
		while (i < philo->data->num_philo)
		{
			pthread_mutex_lock(&philo->data->dead);
			if (current_time() - philo[i].last_eat >= philo->data->time_to_die)
			{
				philo->check_dead = 1;
				print_msg("died", &philo[i]);
				break ;
			}
			pthread_mutex_unlock(&philo->data->dead);
			i++;
		}
		if (philo->check_dead == 1){
			printf("here\n");
			return (1);
		}
			
		if (check_meals(philo))
			return (1);
	}
	return (0);
}
