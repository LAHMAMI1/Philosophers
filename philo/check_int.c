/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:44:24 by olahmami          #+#    #+#             */
/*   Updated: 2023/08/29 20:48:23 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_atoi(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-2);
		result = result * 10 + str[i++] - 48;
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (-2);
	}
	return (result * sign);
}

int	check_args(char **av)
{
	int i;

	i = 0;
	while (av[++i])
	{
		if (check_atoi(av[i]) <= 0)
			return (1);
	}
	return (0);
}