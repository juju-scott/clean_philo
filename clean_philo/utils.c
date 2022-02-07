/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraudo <jgiraudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:47:54 by jgiraudo          #+#    #+#             */
/*   Updated: 2022/02/07 14:15:46 by jgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi_philo(char *str)
{
	int	i;
	int	sign;
	int	atoi;

	i = 0;
	sign = 1;
	atoi = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\n') \
			|| (str[i] == '\r') || (str[i] == '\f') \
			|| (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi = atoi * 10 + str[i] - '0';
		i++;
	}
	return (atoi * sign);
}

long whattimeisit(void)
{
	long		return_value;
	long		actual_time;
	
	return_value = gettimeofday(&quelleheurestil, NULL);
	if (return_value == -1)
	{
		printf("pb dans la recuperation du temps\n");
		exit(EXIT_FAILURE);
	}	
	actual_time = (quelleheurestil.tv_sec * 1000) + (quelleheurestil.tv_usec / 1000); 
	//printf("temps en millissecondes : %ld\n", (quelleheurestil.tv_sec * 1000) + (quelleheurestil.tv_usec / 1000));
	//printf("actual time : %ld\n", actual_time);
	return (actual_time);
}