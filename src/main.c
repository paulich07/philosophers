/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:54:05 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 07:25:39 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	table = (t_table){0};
	if (argc < 5 || argc > 6)
		return (printf("Wrong usage of arguments: "
			"number_of_philosophers time_to_die time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]\n"), 1);
	if (parse_args(&table, argc, argv) != 0)
		return (1);
	// if (argc == 5)
	init_simulation(&table);
	// else if (argc == 6)
	// 	one_philosopher(&table);
	return (0);
}
