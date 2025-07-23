/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:06 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 00:33:04 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	safe_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%s\n", str);
	pthread_mutex_unlock(&philo->table->print);
}

int	set_death(t_table *table)
{
	pthread_mutex_lock(&table->check_death);
	table->death = 1;
	pthread_mutex_unlock(&table->check_death);
}

int	check_death(t_philo *philo)
{
	int	rip;

	pthread_mutex_lock(&philo->table->check_death);
	rip = philo->table->death;
	pthread_mutex_unlock(&philo->table->check_death);
	return (rip);
}
