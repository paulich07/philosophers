/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:06 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 11:02:00 by plichota         ###   ########.fr       */
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
	int status = is_starved_to_death(philo);
	if (status )
	{
     safe_print(philo, "died");
			set_death(philo);
	}
	if (philo->table->number_of_times_each_philosopher_must_eat > 0
		&& is_everyone_satisfied(philo))
			return (safe_print(philo, "end"), 1);
	return (0);
}

// non stampo nulla se death = 1
void	safe_print(t_philo *philo, char *str)
{
	unsigned long long	t;

	pthread_mutex_lock(&philo->table->print);
	if (is_dead(philo))
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	t = get_system_time_ms() - philo->table->start_time;
	printf("%-6llu %-4d %s\n", t, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}

int		is_everyone_satisfied(t_philo *philo)
{
	int	status;

	if (philo->table->number_of_times_each_philosopher_must_eat <= 0)
		return (0);
	pthread_mutex_lock(&philo->table->satisfied);
	if (philo->table->n_satisfied_philo >= philo->table->number_of_philosophers)
		status = 1;
	pthread_mutex_unlock(&philo->table->satisfied);
	// if (status > 0)
	// 	set_death(philo);
	return (status);
}