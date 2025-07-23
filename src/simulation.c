/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:00:21 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 00:06:00 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/

// creo array di forks (mutex)
// vengono salvati in common mutexes
int	init_forks(t_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(table->number_of_philosophers
			* sizeof(pthread_mutex_t));
	if (!table->forks)
		return (printf("Error creating forks array\n"), 1);
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (0);
}

// inizializzo common mutexes
int	init_common_mutex(t_table *table)
{
	if (init_forks(table) != 0)
		return (1);
	pthread_mutex_init(&table->check_death, NULL);
	pthread_mutex_init(&table->print, NULL);
	return (0);
}

void	init_philosophers(t_philo *philosophers, t_table *table)
{
	int	i;
	int	n_of_philosophers;

	i = 0;
	n_of_philosophers = table->number_of_philosophers;
	while (i < table->number_of_philosophers)
	{
		philosophers[i].id = i;
		philosophers[i].meals = 0;
		philosophers[i].starving_time = 0;
		philosophers[i].fork_left = &table->forks[i];
		philosophers[i].fork_left = &table->forks[(i + 1) % n_of_philosophers];
		philosophers[i].table = table;
		i++;
	}
}

int	init_threads(t_philo *philosophers, t_table *table)
{
	
}

// initialize structs, forks, mutexes, threads.
// run simulation
int	init_simulation(t_table *table)
{
	t_philo	*philosophers;

	philosophers = malloc(table->number_of_philosophers * sizeof(t_philo));
	if (!philosophers)
		return (printf("Error creating philosophers array\n"),
			free(philosophers), 1);
	if (init_common_mutex(table) != 0)
		return (printf("Error initializing common mutex\n"),
			free(philosophers), 2);
	init_philosophers(philosophers, table);
	if (init_threads(philosophers, table) != 0)
		return (printf("Error initializing threads\n"),
			free(philosophers), free_table(table), 3);
}
