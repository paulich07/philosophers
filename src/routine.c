/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:13:09 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 03:15:04 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// todo attenzione unlockare tutti i mutex prima di uscire
// per liberare mutex bisogna fare un pthread_mutex_unlock per ogni pthread_mutex_lock
// VERSIONE SENZA MONITOR
// MENTRE PRENDE FORCHETTE NON RILEVA SUBITO MORTE
void	*eat_sleep_think_routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) arg;
	table = philo->table;
	while (!check_table_death(philo))
	{
		take_forks(philo);
		eat(philo);
		sleep(philo);
		think(philo);
	}
	// unlock_forks(philo);
	return (NULL);
}
