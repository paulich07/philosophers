/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 01:48:41 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 01:51:48 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// to do aggiungere altri controlli morte (+ sync)
int	check_starving_death(t_philo *philo)
{
	if ()
	{
    set_death(philo->table);
		safe_print(philo, "died");
		return (1);
	}
	return (0);
}