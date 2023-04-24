/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taybakan <taybakan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 04:10:04 by taybakan          #+#    #+#             */
/*   Updated: 2023/04/24 11:50:59 by taybakan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef unsigned long long	t_time;

typedef struct s_data
{
	int						is_dead;
	int						is_ate;
}							t_data;

typedef struct s_philo
{
	t_data					*data;
	int						id;
	int						n_philo;
	int						t_die;
	int						t_eat;
	int						t_sleep;
	int						n_eat;
	int						total_eat;
	int						finished;
	int						rip;
	t_time					last_eat;
	t_time					t_init;
	pthread_t				thread;
	pthread_mutex_t			*death;
	pthread_mutex_t			*plate;
	pthread_mutex_t			*write;
	pthread_mutex_t			*left_fork_mutex;
	pthread_mutex_t			*right_fork_mutex;
}							t_philo;

typedef struct s_args
{
	int						n_philo;
	t_philo					**philo;
}							t_args;

int							ft_atol(char *str);
int							ft_checkinput(char **argv);
int							ft_mutex_creat(t_args *args);
int							thread_init(t_args *args);
int							ft_mutex_init(t_args *args);
int							ph_wait(int p_time, int w_time);
void						*routine(t_philo *philo);
int							ft_creat(int argc, char **argv, t_args *args,
								t_data *data);
int							getforks(t_philo *philo);
int							dinner(t_philo *philo);
int							ph_sleep(t_philo *philo);
int							ph_write(t_philo *philo, char *status);
int							ft_strncmp(const char *s1, const char *s2,
								size_t n);
int							ft_isdigit(int c);
t_time						ft_get_time(void);
void						ft_bzero(void *s, size_t n);
void						*ft_calloc(size_t count, size_t size);
int							is_ate(t_args *args);
int							azrael(t_args *args);
int							ft_is_dead(t_philo *philo);
int							thread_detach(t_args *args);
void						ft_free(t_args *args);
int							*args_to_die(t_args *args, int i);
int							ft_check(char *str);

#endif
