/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:30:20 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 05:02:38 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *philosophers, t_table *table)
{
	int	i;

	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
}

