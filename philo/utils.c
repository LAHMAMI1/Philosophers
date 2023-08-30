/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahmami <olahmami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 02:11:11 by olahmami          #+#    #+#             */
/*   Updated: 2023/08/30 03:19:46 by olahmami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long current_time_in_milliseconds() {
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    long milliseconds = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
    return (milliseconds);
}

