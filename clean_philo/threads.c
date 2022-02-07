/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraudo <jgiraudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:21:42 by jgiraudo          #+#    #+#             */
/*   Updated: 2022/02/07 15:51:19 by jgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_threads(t_node *philo)
{
	int i;
    i = 0;

    while (i < philo->nb_of_philo)
    {
        pthread_create(&philo->thread, NULL, &ft_routine_philo, (void *)philo);
		pthread_join(philo->thread, NULL);
        if (philo->next != NULL)
	    	philo = philo->next;
        i++;
    }
}
void	ft_create_philo(t_node *philo, char **argv)
{
	printf("création de la liste chainée de philo \n");
	
	t_node *temp;
    
	int i;
	i = 1;

	while (i < philo->nb_of_philo) // ici je crée les autres philos
	{	
		temp = ft_new_philo(philo, argv, i); 
		add_back_node(&philo, temp);
		i++;
	}
	ft_print_list(philo);
	ft_create_threads(philo);
}