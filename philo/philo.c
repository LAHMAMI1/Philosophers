/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 10:18:33 by olahmami          #+#    #+#             */
/*   Updated: 2023/08/26 00:03:30 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	mutex;
int				tester = 0;

void	*test(void)
{
	int	i;

	i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex);
		tester++;
		i++;
		pthread_mutex_unlock(&mutex);
	}
}

int	main(int ac, char **av)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&thread1, NULL, &test, NULL);
	pthread_create(&thread2, NULL, &test, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&mutex);
	printf("this is i: {%d}\n", tester);
	return (0);
}