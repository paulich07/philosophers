/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:06 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 07:52:21 by plichota         ###   ########.fr       */
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
		pthread_mutex_lock(&philo->table->access_starving);
		if ((now - philo->start_starving_time) > philo->table->time_to_die)
		{
			philo->table->death = 1;
			status = 1;
		}
		pthread_mutex_unlock(&philo->table->access_starving);

		if (philo->table->number_of_times_each_philosopher_must_eat > 0)
		{
			pthread_mutex_lock(&philo->table->satisfied);
			if (!status && philo->table->n_satisfied_philo == philo->table->number_of_philosophers)
			{
				philo->table->death = 1;
				status = 2;
			}
			pthread_mutex_unlock(&philo->table->satisfied);
		}
	}
	pthread_mutex_unlock(&philo->table->check_death);
	if (status == 1)
		safe_print(philo, "died");
	else if (status == 2)
		safe_print(philo, "end");
	return (status);
}

// non stampo nulla se death = 1
void	safe_print(t_philo *philo, char *str)
{
	unsigned long long	t;

	pthread_mutex_lock(&philo->table->print);
	if (philo->table->death != 0)
	{
		pthread_mutex_unlock(&philo->table->print);
		return ;
	}
	t = get_system_time_ms() - philo->table->start_time;
	printf("%-6llu %-4d %s\n", t, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}

