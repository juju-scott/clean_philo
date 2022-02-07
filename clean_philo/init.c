/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraudo <jgiraudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:45:26 by jgiraudo          #+#    #+#             */
/*   Updated: 2022/02/07 15:47:54 by jgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_struct(t_node *philo, char **argv)
{
	philo->nb_of_philo = ft_atoi_philo(argv[1]); /* déterminer le nb de philo aka le nb de threads */
	philo->id = 1;
	philo->time_to_die = ft_atoi_philo(argv[2]);
	philo->time_to_eat = ft_atoi_philo(argv[3]);
	philo->time_to_sleep = ft_atoi_philo(argv[4]);
	philo->start = 0;
	philo->soustraction = 0;
	//printf("nb of philo : %d \n", philo->nb_of_philo);
}

