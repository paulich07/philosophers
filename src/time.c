/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:31:02 by plichota          #+#    #+#             */
/*   Updated: 2025/07/22 19:17:23 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// get the current time in milliseconds
unsigned long long	get_current_time_in_ms(void)
{
	struct timeval		timeval;
	unsigned long long	time_in_milliseconds;

	gettimeofday(&timeval, NULL);
	time_in_milliseconds = (timeval.tv_sec * 1000) + (timeval.tv_usec / 1000);
	return (time_in_milliseconds);
}

// get the time elapsed since the start of the simulation
unsigned long long	get_time_in_ms(t_params params)
{
	return (get_current_time_in_ms() - params.start_time);
}
