/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:26:24 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 06:07:35 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// aspetta lentamente la sua morte con una sola forchetta in mano
int	handle_single_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	if (check_table_death(philo))
	{
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	safe_print(philo, "has taken a fork");
	while (!check_table_death(philo))
		usleep(100);
	pthread_mutex_unlock(philo->fork_left);
	return (check_table_death(philo));
}

// i filosofi pari prendono prima la forchetta a sinistra
int	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	if (check_table_death(philo))
	{
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	safe_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_right);
	if (check_table_death(philo))
	{
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	safe_print(philo, "has taken a fork");
	return (check_table_death(philo));
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
		if (check_table_death(philo))
		{
			pthread_mutex_unlock(philo->fork_right);
			return (1);
		}
		safe_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_left);
		if (check_table_death(philo))
		{
			pthread_mutex_unlock(philo->fork_right);
			pthread_mutex_unlock(philo->fork_left);
			return (1);
		}
		safe_print(philo, "has taken a fork");
	}
	return (check_table_death(philo));
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
	philo->start_starving_time = get_system_time_ms();
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	return (check_table_death(philo));
}

int	ft_sleep(t_philo *philo)
{
	if (check_table_death(philo))
		return (1);
	safe_print(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
	return (check_table_death(philo));
}

int	think(t_philo *philo)
{
	if (check_table_death(philo))
		return (1);
	safe_print(philo, "is thinking");
	usleep(100); // opzionale
	return (check_table_death(philo));
}