/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:48:41 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 03:29:53 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pass NULL if you don't want to release a fork
// or if the fork is already unlocked
// void release_forks(pthread_mutex_t *left, pthread_mutex_t *right)
// {
// 	if (left)
// 		pthread_mutex_unlock(left);
// 	if (right)
// 		pthread_mutex_unlock(right);
// }


int	check_starving_death(t_philo *philo)
{
  unsigned long long	now;

  now = get_system_time_ms();
	if (now - philo->start_starving_time > philo->table->time_to_die)
	{
    set_death(philo->table);
		safe_print_after_death(philo, "died");
		return (1);
	}
	return (0);
}
