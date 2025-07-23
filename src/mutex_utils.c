/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:06 by plichota          #+#    #+#             */
/*   Updated: 2025/07/23 22:02:54 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philo)
{
	int	i;

	i = 0;
	// prendo il mutex di check_death del filosofo
	// salvo risultato nella variabile i
	// unlock del mutex
	return (i);
}

void	*eat_sleep_think_routine(void *arg)
{
	t_philo		*philo;
	t_params	*table;

	philo = (t_philo *) arg;
	table = philo->table;
	while (!check_death(philo))
	{
		// take forks and eat
	
		// sleep
	
		// think
	}
	return (NULL);
}

