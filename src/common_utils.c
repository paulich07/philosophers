/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:06 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 04:39:38 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// end simulation if
// - someone in the table has died
// - philo has reached time_to_die
// - everyone has reached the number of meals
// return 1 if someone has died
int	check_table_death(t_philo *philo)
{
	int	status;
  unsigned long long	now;

	pthread_mutex_lock(&philo->table->check_death);
	status = philo->table->death;
	if (!status)
	{
		now = get_system_time_ms();
		if ((now - philo->start_starving_time) > philo->table->time_to_die)
		{
			philo->table->death = 1;
			safe_print_after_death(philo, "died");
			status = 1;
		}
	}
	// check if everyone has eaten all the meals
	pthread_mutex_unlock(&philo->table->check_death);
	return (status);
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
