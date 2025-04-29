/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:51:09 by plichota          #+#    #+#             */
/*   Updated: 2025/04/29 16:56:41 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef MAX_ALLOWED_THREADS
#  define MAX_ALLOWED_THREADS = 10000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <pthread.h> // aggiungi -pthread in coompilazione
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>

#endif