/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:51:09 by plichota          #+#    #+#             */
/*   Updated: 2025/07/24 04:58:30 by plichota         ###   ########.fr       */
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
	int									number_of_philosophers;
	unsigned long long	time_to_die;
	unsigned long long	time_to_eat;
	unsigned long long	time_to_sleep;
	int									number_of_times_each_philosopher_must_eat;
	int									death;
	unsigned long long	start_time;
	int									n_satisfied_philo;
	pthread_mutex_t			check_death;
	pthread_mutex_t			print;
	pthread_mutex_t			satisfied;
	pthread_mutex_t			*forks;
}	t_table;

typedef struct s_philo
{
	int									id;
	int									meals;
	unsigned long long	start_starving_time;
	pthread_t						thread;
	pthread_mutex_t			*fork_left;
	pthread_mutex_t			*fork_right;
	t_table							*table;
}	t_philo;


// Parsing
void				assign_params(t_table *table, int argc, char *argv[]);
int					parse_args(t_table *table, int argc, char *argv[]);

// Simulation
int					init_forks(t_table *table);
int					init_common_mutex(t_table *table);
void				init_philosophers(t_philo *philosophers, t_table *table);
int					init_threads(t_philo *philosophers, t_table *table);
int					init_simulation(t_table *table);

void				join_threads(t_philo *philosophers, t_table *table);
int					one_philosopher(t_table *table);

// Routine
void				*eat_sleep_think_routine(void *arg);

// Actions
void				take_forks_even(t_philo *philo);
void				take_forks(t_philo *philo);
void				eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				think(t_philo *philo);

// Common Utils
int					check_table_death(t_philo *philo);
void				safe_print_after_death(t_philo *philo, char *str);
void				safe_print(t_philo *philo, char *str);
void				set_death(t_table *table);

// Philo Utils

// Cleanup
void				free_forks(pthread_mutex_t *forks, int n);
int					free_table(t_table *table);

// Time
unsigned long long	get_system_time_ms(void);
unsigned long long	get_timestamp(t_table *table);

// Utils
int					ft_atoi(const char *str);
int 				is_number(char *s);

#endif