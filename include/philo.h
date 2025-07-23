/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:51:09 by plichota          #+#    #+#             */
/*   Updated: 2025/07/23 22:05:51 by plichota         ###   ########.fr       */
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

// mutex di monitoraggio e stampa
typedef struct s_mutex
{
	pthread_mutex_t	check_death;
	pthread_mutex_t	log;
	pthread_mutex_t	*forks;
	// pthread_mutex_t	check_n_meals;
	// pthread_mutex_t	update_starving_time;
	// pthread_mutex_t	update_meals;
}	t_mutex;

typedef struct s_params
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	int					died;
	unsigned long long	start_time;
}	t_params;

typedef struct s_philo
{
	int					id;
	int					meals;
	unsigned long long	starving_time;
	pthread_mutex_t		*fork_left;
	pthread_mutex_t		*fork_right;
	t_params			*table;
}	t_philo;

#endif