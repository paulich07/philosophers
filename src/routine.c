/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:13:09 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 01:48:28 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// attenzione liberare tutti i mutex prima di uscire
// per liberare mutex bisogna fare un pthread_mutex_unlock per ogni pthread_mutex_lock
void	*eat_sleep_think_routine(void *arg)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) arg;
	table = philo->table;
	while (!check_death(philo)) // to do aggiungere altri controlli morte (+ sync)
	{
		// to do controllare starving time che causa morte
		take_forks(philo);
		eat(philo);
		sleep(philo);
		think(philo);
	}
	unlock_forks(philo);
	return (NULL);
}
