/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:00:21 by plichota          #+#    #+#             */
/*   Updated: 2025/07/23 23:00:00 by plichota         ###   ########.fr       */
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
int	init_forks(t_mutex *mutex, t_params *params)
{
	int	i;

	i = 0;
	mutex->forks = malloc(params->number_of_philosophers
			* sizeof(pthread_mutex_t));
	if (!mutex->forks)
		return (printf("Error creating forks array\n"), 1);
	while (i < params->number_of_philosophers)
	{
		pthread_mutex_init(&mutex->forks[i], NULL);
		i++;
	}
	return (0);
}

// inizializzo common mutexes
int	init_common_mutex(t_mutex *mutex, t_params *params)
{
	if (init_forks(mutex, params) != 0)
		return (1);
	pthread_mutex_init(&mutex->check_death, NULL);
	pthread_mutex_init(&mutex->log, NULL);
	return (0);
}

// initialize threads, forks, mutexes, etc.
// run simulation
int	init_simulation(t_params *params)
{
	t_philo	*philosophers;
	t_mutex	common_mutex;

	philosophers = malloc(params->number_of_philosophers * sizeof(t_philo));
	if (!philosophers)
		return (printf("Error creating philosophers array\n"), 1);
	if (init_common_mutex(&common_mutex, &params) != 0)
		return (printf("Error initializing common mutex\n"), 1);

		// pthread_t philosophers[params.number_of_philosophers];
	// int i;
	// t_philo philo[params.number_of_philosophers];

	// pthread_mutex_init(&mutex, (void *)(&params));
	// i = 0;
	// while (i < params.number_of_philosophers)
	// {
	// 	// posso passare un solo param quindi aggiungo al filosofo il table
	// 	if(pthread_create(&philosophers[i], NULL, &RUN SIMULATION, &philosopher) != 0)
	// 		return (printf("Error creating thread\n"), 1);
	// 	i++;
	// 	printf("Philosopher %d created\n", i);
	// }
	// i = 0;
	// while (i < params.number_of_philosophers)
	// {
	// 	if(pthread_join(philosophers[i], NULL) != 0)
	// 		return (printf("Error joining thread\n"), 1);
	// 	i++;
	// 	printf("Philosopher %d joined the table\n", i);
	// }
	// pthread_mutex_destroy(&mutex);
}
