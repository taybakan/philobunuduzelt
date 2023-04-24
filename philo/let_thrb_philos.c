/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_thrb_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 01:32:14 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/24 11:50:09 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_init(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n_philo)
	{
		if (pthread_mutex_init(args->philo[i]->left_fork_mutex, NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(args->philo[0]->write, NULL))
		return (1);
	if (pthread_mutex_init(args->philo[0]->plate, NULL))
		return (1);
	if (pthread_mutex_init(args->philo[0]->death, NULL))
		return (1);
	return (0);
}

int	ft_mutex_creat(t_args *args)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*w;
	pthread_mutex_t	*pl;
	pthread_mutex_t	*dh;

	forks = malloc(sizeof(pthread_mutex_t) * args->n_philo);
	w = malloc(sizeof(pthread_mutex_t));
	pl = malloc(sizeof(pthread_mutex_t));
	dh = malloc(sizeof(pthread_mutex_t));
	i = 0;
	while (i < args->n_philo)
	{
		args->philo[i]->right_fork_mutex = &forks[i];
		args->philo[i]->left_fork_mutex = &forks[(i + 1) % args->n_philo];
		args->philo[i]->write = &w[0];
		args->philo[i]->plate = &pl[0];
		args->philo[i]->death = &dh[0];
		i++;
	}
	return (ft_mutex_init(args));
}

int	ft_creat(int argc, char **argv, t_args *args, t_data *data)
{
	int		i;

	args->n_philo = ft_atol(argv[1]);
	if (args->n_philo == 0)
		return (1);
	data->is_dead = 0;
	data->is_ate = 0;
	args->philo = malloc(sizeof(t_philo *) * args->n_philo);
	i = -1;
	while (++i < args->n_philo)
	{
		args->philo[i] = malloc(sizeof(t_philo));
		args->philo[i]->id = (i + 1);
		args->philo[i]->finished = 0;
		args->philo[i]->n_philo = ft_atol(argv[1]);
		args->philo[i]->t_die = ft_atol(argv[2]);
		args->philo[i]->t_eat = ft_atol(argv[3]);
		args->philo[i]->t_sleep = ft_atol(argv[4]);
		args->philo[i]->data = data;
		if (argc == 6)
			args->philo[i]->n_eat = ft_atol(argv[5]);
		else
			args->philo[i]->n_eat = -1;
	}
	return (ft_mutex_creat(args));
}
