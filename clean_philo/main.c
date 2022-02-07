/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraudo <jgiraudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:27:28 by jgiraudo          #+#    #+#             */
/*   Updated: 2022/02/07 15:36:44 by jgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	/* initialisation des variables */
	t_node philo;

	/* verification des arguments */
	check_number_of_arg(argc, argv);

	/* initialisation de la structure */
	ft_init_struct(&philo, argv);
	
	/* création des threads */
	//ft_create_threads(&data_philo);
	
	ft_create_philo(&philo, argv);
	//ft_free_list(philo);
	
	return 0;
}