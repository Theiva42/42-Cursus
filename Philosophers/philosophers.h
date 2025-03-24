/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:01 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/03 15:24:29 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

struct s_table;

typedef struct s_philo
{
	int id;
	int eat_count;
	pthread_t thread;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	long long last_meal_time;
	struct s_table *table;
}t_philo;

typedef struct s_table
{
	int	no_of_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int simulation_running;
	int	num_times_each_philosopher_must_eat;
	int finished_philosophers;
	pthread_mutex_t *forks;
	pthread_mutex_t print_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t simulation_lock;
	pthread_mutex_t finished_lock;
	t_philo	*philo;
}t_table;

void	start_simulation(int argc, char **argv);
long long	current_time();
void	print_action(t_table *table, int id, char *action);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_isnum(char* c);


#endif
