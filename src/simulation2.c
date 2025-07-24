/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:30:20 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 18:23:29 by plichota         ###   ########.fr       */
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
// È ora di morire? È ora di morire? È ora di morire?
int	handle_single_philosopher(t_philo *philo)
{
	unsigned long long	death_time;

	death_time = philo->table->start_time + philo->table->time_to_die;
	pthread_mutex_lock(philo->fork_left);
	safe_print(philo, "has taken a fork");
	while (get_system_time_ms() < death_time)
		usleep(50);
	pthread_mutex_unlock(philo->fork_left);
	safe_print(philo, "died");
	set_death(philo);
	return (1);
}
