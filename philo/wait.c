/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:14:27 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/24 11:32:55 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_wait(int p_time, int w_time)
{
	t_time	t;

	t = ft_get_time();
	while ((int)(t - p_time) < w_time)
	{
		t = ft_get_time();
		usleep(3);
	}
	return (0);
}
