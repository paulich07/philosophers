/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:06 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 07:46:25 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_starving(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->access_starving);
	philo->start_starving_time = get_system_time_ms();
	pthread_mutex_unlock(&philo->table->access_starving);
}

unsigned long long	get_starving_time(t_philo *philo)
{
	unsigned long long	t;
	pthread_mutex_lock(&philo->table->access_starving);
	t = philo->start_starving_time;
	pthread_mutex_unlock(&philo->table->access_starving);
	return (t);
}