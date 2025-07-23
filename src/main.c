/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:54:05 by plichota          #+#    #+#             */
/*   Updated: 2025/07/23 22:08:05 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_params	params = {0};

	if (argc < 5 || argc > 6)
		return (printf("Wrong usage of arguments\n"), 1);
	if (parse_args(&params, argc, argv) != 0)
		return (1);
	assign_params(&params, argc, argv);
	params.start_time = get_time_in_ms();
	if (argc == 5)
		init_simulation(params);
	else if (argc == 6)
		one_philosopher(params);
}
