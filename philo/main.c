/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:26:43 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/24 11:49:56 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(args->philo[0]->death);
	pthread_mutex_destroy(args->philo[0]->plate);
	pthread_mutex_destroy(args->philo[0]->write);
	free(args->philo[0]->death);
	free(args->philo[0]->plate);
	free(args->philo[0]->write);
	free(args->philo[0]->data);
	free(args->philo[0]->right_fork_mutex);
	while (i < args->n_philo)
	{
		pthread_mutex_destroy(args->philo[i]->right_fork_mutex);
		i++;
	}
	free(args->philo);
	free(args);
}

int	main(int argc, char **argv)
{
	t_args	*args;
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (1);
	if (ft_checkinput(argv))
		return (1);
	args = malloc(sizeof(t_args));
	data = malloc(sizeof(data));
	if (ft_creat(argc, argv, args, data))
		return (1);
	if (thread_init(args))
		return (1);
	usleep(1000);
	azrael(args);
	if (thread_detach(args))
		return (1);
	ft_free(args);
	return (0);
}
