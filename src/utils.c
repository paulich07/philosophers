/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plichota <plichota@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:12:17 by plichota          #+#    #+#             */
/*   Updated: 2025/07/22 13:29:26 by plichota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\f'
		|| c == '\n' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

int is_number(char *s)
{
	if (!s)
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	while (*s != '\0')
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}