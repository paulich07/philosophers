/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:30:20 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 17:07:24 by plichota         ###   ########.fr       */
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

// aspetta lentamente la sua morte con una sola forchetta in mano
int	handle_single_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	safe_print(philo, "has taken a fork");
	while (!check_table_death(philo))
		usleep(100);
	pthread_mutex_unlock(philo->fork_left);
	return (0);
}
