/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:26:24 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 04:08:14 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// to do vedere se va altrimenti mettere handler immediatamente
// prende una sola forchetta
void	handle_single_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	if (check_table_death(philo))
	{
		pthread_mutex_unlock(philo->fork_left);
		return ;
	}
	safe_print(philo, "has taken a fork");
	// if (philo->table->n_philo == 1)
	// {
	// 	pthread_mutex_lock(philo->fork_left);
	// 	safe_print(philo, "has taken a fork");
	// 	while (!check_table_death(philo))
	// 		usleep(100);
	// 	pthread_mutex_unlock(philo->fork_left);
	// 	return ;
	// }
}

// i filosofi pari prendono prima la forchetta a sinistra
void	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	if (check_table_death(philo))
	{
		pthread_mutex_unlock(philo->fork_left);
		return ;
	}
	safe_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork_right);
	if (check_table_death(philo))
	{
			pthread_mutex_unlock(philo->fork_left);
			pthread_mutex_unlock(philo->fork_right);
		return ;
	}
	safe_print(philo, "has taken a fork");
}

// per evitare deadlock i filosofi pari prendono prima a sinistra
// e i filosofi dispari prendono prima a destra
void	take_forks(t_philo *philo)
{
	if (philo->table->number_of_philosophers == 1)
		handle_single_philosopher(philo);
	else if (philo->id % 2 == 0)
		take_forks_even(philo);
	else
	{
		pthread_mutex_lock(philo->fork_right);
		if (check_table_death(philo))
		{
			pthread_mutex_unlock(philo->fork_right);
			return ;
		}
		safe_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_left);
		if (check_table_death(philo))
		{
			pthread_mutex_unlock(philo->fork_right);
			pthread_mutex_unlock(philo->fork_left);
			return ;
		}
		safe_print(philo, "has taken a fork");
	}
}

// mangio, sblocco forchette e aggiorno start_starving_time
void	eat(t_philo *philo)
{
	if (check_table_death(philo) != 0)
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return ;
	}
	safe_print(philo, "is eating");
	philo->meals++;
	philo->start_starving_time = get_system_time_ms();
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

void	ft_sleep(t_philo *philo)
{
	if (check_table_death(philo))
		return ;
	safe_print(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (check_table_death(philo))
		return ;
	safe_print(philo, "is thinking");
	usleep(100); // opzionale
}