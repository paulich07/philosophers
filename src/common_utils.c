/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:06 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 04:00:45 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_table_death(t_philo *philo)
{
	int	rip;

	pthread_mutex_lock(&philo->table->check_death);
	rip = philo->table->death;
	pthread_mutex_unlock(&philo->table->check_death);
	return (rip);
}

void	safe_print_after_death(t_philo *philo, char *str)
{
	unsigned long long	t;

	pthread_mutex_lock(&philo->table->print);
	t = get_system_time_ms() - philo->table->start_time;
	printf("%-6llu %-4d %s\n", t, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}

// non stampo nulla se death = 1
// potrebbe esserci race condition se 
void	safe_print(t_philo *philo, char *str)
{
	unsigned long long	t;

	pthread_mutex_lock(&philo->table->print);
	if (check_table_death(philo) != 0)
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	t = get_system_time_ms() - philo->table->start_time;
	printf("%-6llu %-4d %s\n", t, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}

void	set_death(t_table *table)
{
	pthread_mutex_lock(&table->check_death);
	table->death = 1;
	pthread_mutex_unlock(&table->check_death);
}
