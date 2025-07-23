/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:26:24 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 01:42:14 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// per evitare deadlock i filosofi pari prendono prima a destra
// e i filosofi dispari prendono prima a sinistra
void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_left);
		safe_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_right);
		safe_print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->fork_right);
		safe_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_left);
		safe_print(philo, "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	safe_print(philo, "is eating");
	philo->meals++;
	philo->start_starving_time = get_system_time_ms();
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	sleep(t_philo *philo)
{
	safe_print(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	safe_print(philo, "is thinking");
	usleep(100);
}