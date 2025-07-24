/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 23:48:32 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 04:08:27 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Attenzione: unlockare i mutex prima di distruggerli
void	free_forks(pthread_mutex_t *forks, int n)
{
	int	i;

	i = 0;
	if (!forks)
		return ;
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}

int	free_table(t_table *table)
{
	free_forks(table->forks, table->number_of_philosophers);
	pthread_mutex_destroy(&table->check_death);
	pthread_mutex_destroy(&table->print);
	return (0);
}
