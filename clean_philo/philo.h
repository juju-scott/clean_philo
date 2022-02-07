/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraudo <jgiraudo@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:47:55 by jgiraudo          #+#    #+#             */
/*   Updated: 2022/02/07 15:33:14 by jgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include <pthread.h>
# include <sys/time.h>

/*structure timeval */
struct timeval quelleheurestil;

/*structure d'un maillon*/
typedef struct s_node
{
	struct s_node	*next;
	struct s_node 	*first;
	
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			time_to_die;
	int				id;
	int				nb_of_philo;
	pthread_t		thread;
	pthread_mutex_t	fork;
	
	long			start;
	long			soustraction;
	
}				t_node;

/*parsing*/
int		check_number_of_arg(int argc, char **argv);
void	check_valid_arg(char **argv);

/*initialisation*/
void	ft_init_struct(t_node *philo, char **argv);
void	ft_free_list(t_node *philo);
void	ft_print_list(t_node *philo);
void	add_back_node(t_node **philo, t_node *new);
t_node	*ft_last_node(t_node *philo);
t_node	*ft_first_node(t_node *philo);

/*threads*/
void	ft_create_philo(t_node *philo, char **argv);

/*routine*/
void *ft_routine_philo(void *arg);
void check_fork(t_node *philo);
void thinking_philo(t_node *philo);
void sleeping_philo(t_node *philo);


/*utils_chained_list*/
t_node	*ft_new_philo(t_node *philo, char **argv, int i);

/*utils*/
int		ft_atoi_philo(char *str);
long 	whattimeisit(void);


#endif
