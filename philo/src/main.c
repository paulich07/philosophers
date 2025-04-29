/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:54:05 by plichota          #+#    #+#             */
/*   Updated: 2025/04/29 21:26:08 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
*/

int main(int argc, char *argv[])
{
  int number_of_philosophers;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int number_of_times_each_philosopher_must_eat;

  if (argc < 5 || argc > 6)
    return (printf("Wrong usage of arguments\n"), 0);
  
  if (!is_number(argv[1]))
    return (printf("Invalid first argument\n"), 0);
  number_of_philosophers = ft_atoi(argv[1]);
  // qual è il massimo?
  if (number_of_philosophers <= 0)
    return (printf("Invalid number of philosophers\n"), 0);

  if (!is_number(argv[2]))
    return (printf("Invalid second argument\n"), 0);
  time_to_die = ft_atoi(argv[2]);
  // può essere 0?? max?
  if (time_to_die <= 0)
    return (printf("Invalid time_to_die\n"), 0);

  if (!is_number(argv[3]))
    return (printf("Invalid third argument\n"), 0);
  time_to_eat = ft_atoi(argv[3]);
  // può essere 0?? max?
  if (time_to_eat <= 0)
    return (printf("Invalid time_to_eat\n"), 0);

  if (!is_number(argv[4]))
    return (printf("Invalid fourth argument\n"), 0);
  time_to_sleep = ft_atoi(argv[4]);
  // può essere 0?? max?
  if (time_to_sleep <= 0)
    return (printf("Invalid time_to_sleep\n"), 0);

  if (argc == 6)
  {
    if (!is_number(argv[5]))
      return (printf("Invalid fifth argument\n"), 0);
    number_of_times_each_philosopher_must_eat = ft_atoi(argv[4]);
    // può essere 0?? max?
    if (number_of_times_each_philosopher_must_eat <= 0)
      return (printf("Invalid number_of_times_each_philosopher_must_eat\n"), 0);
  }
  /*
  If all philosophers have eaten at least number_of_times_each_philosopher_must_eat
  times, the simulation stops.
  */
}
