/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:30:20 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 02:44:38 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *philosophers, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
}

// case one philosopher (can't eat)
int	one_philosopher(t_table *table)
{
	table->start_time = get_time_in_ms(); // poco prima del thread
	// takes fork (print)
	// usleep
	// dies after time_to_die (print)
	return (0);
}
