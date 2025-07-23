/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:51:09 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 00:33:16 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef MAX_ALLOWED_THREADS
#  define MAX_ALLOWED_THREADS 10000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <pthread.h> // aggiungi -pthread in compilazione
# include <sys/time.h>
# include <sys/wait.h>

typedef struct s_table
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	int					death;
	unsigned long long	start_time;
	pthread_mutex_t		check_death;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
}	t_table;

typedef struct s_philo
{
	int					id;
	int					meals;
	unsigned long long	starving_time;
	pthread_t			thread;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	t_table				*table;
}	t_philo;


// Parsing
void				assign_params(t_table *table, int argc, char *argv[]);
int					parse_args(t_table *table, int argc, char *argv[]);

// Simulation
int					init_simulation(t_table *table);
int					one_philosopher(t_table *table);

// Routine
void				*eat_sleep_think_routine(void *arg);

// Actions
void				take_forks_and_eat(t_philo *philo);

// Common
void				safe_print(t_philo *philo, char *str);
int					set_death(t_table *table);
int					check_death(t_philo *philo);

// Cleanup
void				free_forks(pthread_mutex_t *forks, int n);
int					free_table(t_table *table);

// Time
unsigned long long	get_system_time_in_ms(void);
unsigned long long	get_program_time(t_table *table);

#endif