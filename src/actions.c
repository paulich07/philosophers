/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:26:24 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 17:08:00 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// i filosofi pari prendono prima la forchetta a sinistra
int	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	safe_print(philo, "has taken a fork");
	usleep(100);
	pthread_mutex_lock(philo->fork_right);
	safe_print(philo, "has taken a fork");
	return (0);
}

// per evitare deadlock i filosofi pari prendono prima a sinistra
// e i filosofi dispari prendono prima a destra
int	take_forks(t_philo *philo)
{
	if (philo->table->number_of_philosophers == 1)
		return (handle_single_philosopher(philo));
	else if (philo->id % 2 == 0)
		return (take_forks_even(philo));
	else
	{
		pthread_mutex_lock(philo->fork_right);
		safe_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_left);
		safe_print(philo, "has taken a fork");
	}
	return (0);
}

// mangio, sblocco forchette e aggiorno start_starving_time
int	eat(t_philo *philo)
{
	if (check_table_death(philo) != 0)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	if (philo->fork_left == NULL || philo->fork_right == NULL)
		return (1);
	safe_print(philo, "is eating");
	philo->meals++;
	if (philo->meals == philo->table->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&philo->table->satisfied);
		philo->table->n_satisfied_philo++;
		pthread_mutex_unlock(&philo->table->satisfied);
	}
	update_starving(philo);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (check_table_death(philo));
}

int	ft_sleep(t_philo *philo)
{
	safe_print(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
	return (0);
}

int	think(t_philo *philo)
{
	safe_print(philo, "is thinking");
	usleep(100);
	return (0);
}
