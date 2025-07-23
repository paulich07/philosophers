/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:26:24 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 00:38:41 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// per evitare deadlock i filosofi pari prendono prima a destra
// e i filosofi dispari prendono prima a sinistra
void	take_forks_and_eat(t_philo *philo)
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
