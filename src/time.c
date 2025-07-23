/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:31:02 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 01:35:13 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// get the current time in milliseconds
unsigned long long	get_system_time_ms(void)
{
	struct timeval		timeval;
	unsigned long long	time_in_milliseconds;

	gettimeofday(&timeval, NULL);
	time_in_milliseconds = (timeval.tv_sec * 1000) + (timeval.tv_usec / 1000);
	return (time_in_milliseconds);
}

// get the time elapsed since the start of the simulation
unsigned long long	get_timestamp(t_table *table)
{
	return (get_system_time_ms() - table->start_time);
}
