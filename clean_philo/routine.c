/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraudo <jgiraudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:34:24 by jgiraudo          #+#    #+#             */
/*   Updated: 2022/02/07 16:15:43 by jgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eating_philo(t_node *philo)
{
	philo->soustraction = whattimeisit()- philo->start;
	printf("final time : %ld\n", philo->soustraction);
	if (philo->soustraction < philo->time_to_eat)
	{
		printf("%ldms %d is eating\n", philo->soustraction, philo->id);
		philo->soustraction = whattimeisit() - philo->start;
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork); 
	sleeping_philo(philo);
}

void check_fork(t_node *philo)
{
	philo->soustraction = whattimeisit() - philo->start;

	if (pthread_mutex_unlock(&philo->fork) == 0 && pthread_mutex_unlock(&philo->next->fork) == 0)
	{
		pthread_mutex_lock(&philo->fork);
		printf("%ldms %d has taken his fork\n", philo->soustraction, philo->id);
		pthread_mutex_lock(&philo->next->fork);
		printf("%ldms %d has taken next fork\n", philo->soustraction, philo->id);
		eating_philo(philo);
	}
	else
		thinking_philo(philo);
}

void thinking_philo(t_node *philo)
{
	philo->soustraction = whattimeisit() - philo->start;

	printf("%ldms %d is thinking\n", philo->soustraction, philo->id); //le philo pense
	check_fork(philo); //le philo vérifie si les fork sont dispos

}

void sleeping_philo(t_node *philo)
{
	philo->soustraction = whattimeisit() - philo->start;
	printf("%ldms %d is sleeping\n", philo->soustraction, philo->id);
}

void *ft_routine_philo(void *arg)
{
	t_node *philo;
	
	philo = (t_node *)arg; // permet de passer l'arg en t_philo et de pouvoir l'utiliser
	
	philo->start = whattimeisit(); // HEURE DE DEBUT DE L EXECUTION
	
	if (philo->id % 2 == 0)
		thinking_philo(philo);
	else
		sleeping_philo(philo);
		
    /*savoir si les id des philos sont pairs ou impairs*/
    
	/*if (philo->id % 2 == 0)
		printf("pair manger\n");
	else
		printf("impair TEST\n");*/
	return(arg);

}
