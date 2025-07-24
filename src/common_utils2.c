/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:06 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 11:02:08 by plichota         ###   ########.fr       */
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

int	is_starved_to_death(t_philo *philo)
{
	unsigned long long	now;
	int		status;

	now = get_system_time_ms();
	status = 0;
	pthread_mutex_lock(&philo->table->access_starving);
	if ((now - philo->start_starving_time) > philo->table->time_to_die)
		status = 1;
	pthread_mutex_unlock(&philo->table->access_starving);
	return (status);
}

void  set_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->check_death);
	philo->table->death = 1;
	pthread_mutex_unlock(&philo->table->check_death);
}

int is_dead(t_philo *philo)
{
	int	status;

	pthread_mutex_lock(&philo->table->check_death);
	status = philo->table->death;
	pthread_mutex_unlock(&philo->table->check_death);
	return (status);
}
