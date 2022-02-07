/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_chained_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraudo <jgiraudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:52:31 by jgiraudo          #+#    #+#             */
/*   Updated: 2022/02/07 16:34:11 by jgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

/* fonction qui renvoie le premier element de la liste */
t_node	*ft_first_node(t_node *philo)
{
	if (philo == NULL)
		return (NULL);
	if (philo != NULL)
	{
		if (philo->id == 1)
			return (philo);
	}
	return (philo);
}

/* fonction qui renvoie le dernier element de la liste */
t_node	*ft_last_node(t_node *philo)
{
	if (philo == NULL)
		return (NULL);
	while (philo != NULL)
	{
		if (philo->next == NULL)
			return (philo);
		philo = philo->next;
	}
	return (philo);
}

/* ajoute le maillon apres le suivant */
void	add_back_node(t_node **philo, t_node *new)
{
	t_node	*temp;

	if (philo != NULL && *philo != NULL)
	{
		temp = ft_last_node(*philo);
		temp->next = new;
	}
	else if (philo != NULL)
		*philo = new;
}

/* fonction qui imprime la liste */
void	ft_print_list(t_node *philo)
{
	while (philo)
	{
		printf("le philo a l'id : [%d]\n", philo->id);
		philo = philo->next;
	}
}

void	ft_free_list(t_node *philo)
{
	t_node	*temp_next_node;

	if (philo != NULL)
	{
		while (philo != NULL) //maillon par maillon
		{
			temp_next_node = philo->next; //garder la liaison entre les maillons
			pthread_mutex_destroy(&philo->fork);
			free (philo);
			philo = temp_next_node; // redonner une autre valeur car on vient de le free, on veut garder la liason entre maillons
		}
	}
}

/* fonction qui crée un nouveau maillon */
t_node	*ft_new_philo(t_node *philo, char **argv, int i)
{
	t_node *new_philo;
	
	new_philo = malloc(sizeof(t_node));
	if (!new_philo)
		return (NULL);
	new_philo->next = NULL;
	new_philo->first = ft_first_node(philo);
	
	new_philo->time_to_eat = ft_atoi_philo(argv[3]);
	new_philo->time_to_sleep = ft_atoi_philo(argv[4]);
	new_philo->time_to_die = ft_atoi_philo(argv[2]);
	new_philo->nb_of_philo = ft_atoi_philo(argv[1]);;
	new_philo->id = i + 1;
	pthread_mutex_init(&new_philo->fork, NULL);
	return (new_philo);
}
