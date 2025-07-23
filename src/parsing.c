/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:27 by plichota          #+#    #+#             */
/*   Updated: 2025/07/23 21:27:16 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_params(t_params *params, int argc, char *argv[])
{
	params->number_of_philosophers = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		params->number_of_times_each_philosopher_must_eat = ft_atoi(argv[4]);
}

int	parse_args(t_params *params, int argc, char *argv[])
{
	if (!is_number(argv[1]) || ft_atoi(argv[1]) <= 0)
		return (printf("Invalid first argument\n"), 1);
	if (!is_number(argv[2]) || ft_atoi(argv[2]) <= 0)
		return (printf("Invalid second argument\n"), 1);
	if (!is_number(argv[3]) || ft_atoi(argv[3]) <= 0)
		return (printf("Invalid third argument\n"), 1);
	if (!is_number(argv[4]) || ft_atoi(argv[4]) <= 0)
		return (printf("Invalid fourth argument\n"), 1);
	if (argc == 6)
	{
		if (!is_number(argv[5]) || ft_atoi(argv[5]) <= 0)
			return (printf("Invalid fifth argument\n"), 1);
	}
	return (0);
}
