/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:07:27 by plichota          #+#    #+#             */
/*   Updated: 2025/07/23 23:45:03 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_params(t_table *table, int argc, char *argv[])
{
	table->number_of_philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		table->number_of_times_each_philosopher_must_eat = -1;
}

int	parse_args(t_table *table, int argc, char *argv[])
{
	if (!is_number(argv[1]) || ft_atoi(argv[1]) <= 0)
		return (printf("Invalid number_of_philosophers\n"), 1);
	if (!is_number(argv[2]) || ft_atoi(argv[2]) <= 0)
		return (printf("Invalid time_to_die\n"), 1);
	if (!is_number(argv[3]) || ft_atoi(argv[3]) <= 0)
		return (printf("Invalid time_to_eat\n"), 1);
	if (!is_number(argv[4]) || ft_atoi(argv[4]) <= 0)
		return (printf("Invalid time_to_sleep\n"), 1);
	if (argc == 6 && (!is_number(argv[5]) || ft_atoi(argv[5]) <= 0))
		return (printf("Invalid "
				"number_of_times_each_philosopher_must_eat\n"), 1);
	assign_params(table, argc, argv);
	return (0);
}
