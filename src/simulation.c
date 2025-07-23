/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:00:21 by plichota          #+#    #+#             */
/*   Updated: 2025/07/23 21:28:40 by plichota         ###   ########.fr       */
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

int	init_simulation(t_params params)
{
	pthread_t philosophers[params.number_of_philosophers];
	int i;
	t_philo philo[params.number_of_philosophers];

	pthread_mutex_init(&mutex, (void *)(&params));
	i = 0;
	while (i < params.number_of_philosophers)
	{
		// posso passare un solo param quindi aggiungo al filosofo il table
		if(pthread_create(&philosophers[i], NULL, &RUN SIMULATION, &philosopher) != 0)
			return (printf("Error creating thread\n"), 1);
		i++;
		printf("Philosopher %d created\n", i);
	}
	i = 0;
	while (i < params.number_of_philosophers)
	{
		if(pthread_join(philosophers[i], NULL) != 0)
			return (printf("Error joining thread\n"), 1);
		i++;
		printf("Philosopher %d joined the table\n", i);
	}
	pthread_mutex_destroy(&mutex);
}
