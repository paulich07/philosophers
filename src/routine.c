/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:13:09 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 17:22:25 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// todo attenzione unlockare tutti i mutex prima di uscire
// per liberare mutex bisogna fare un pthread_mutex_unlock
// per ogni pthread_mutex_lock
// VERSIONE SENZA MONITOR
// MENTRE PRENDE FORCHETTE NON RILEVA SUBITO MORTE
// Libera forchette appena intercetta la morte
void	*eat_sleep_think_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (!is_dead(philo))
	{
		if (is_starved_to_death(philo))
		{
			safe_print(philo, "died");
			set_death(philo);
			return (NULL);
		}
		if (is_everyone_satisfied(philo))
			return (NULL);
		if (take_forks(philo))
			break ;
		if (eat(philo))
			break ;
		if (ft_sleep(philo))
			break ;
		think(philo);
	}
	return (NULL);
}
