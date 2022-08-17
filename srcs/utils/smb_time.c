/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:59:04 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:20:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	timestamp_msec(long start)
{
	struct timeval	time;
	long			time_value;

	gettimeofday(&time, 0);
	time_value = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_value - start);
}

long	timestamp_sec(long start)
{
	struct timeval	time;
	long			time_value;

	gettimeofday(&time, 0);
	time_value = time.tv_sec;
	return (time_value - start);
}
