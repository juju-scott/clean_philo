/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraudo <jgiraudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:45:18 by jgiraudo          #+#    #+#             */
/*   Updated: 2022/02/07 13:33:36 by jgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number_of_arg(int argc, char **argv)
{
	if (argc == 5 || argc == 6) // pour gérer le cas où on mettrait le number_of_times_each_philosopher_must_eat)
		check_valid_arg(argv);
	else if (argc != 5)
	{
		printf("Error, number of arg incorrect\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	check_valid_arg(char **argv)
{
	int i;
	int j;
	
	i = 1;
	while (argv[i])
	{
		j = 0;
		if(!argv[i][j])
		{
			printf("ERROR 1 - arg invalides\n");
			exit(EXIT_FAILURE);
		}
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				printf("ERROR 2 - arg invalides\n");
				exit(EXIT_FAILURE);
			}	
			else
				j++;
		}
		i++;
	}
	printf("args valides\n"); 
}