/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:01 by thkumara          #+#    #+#             */
/*   Updated: 2025/04/03 19:03:38 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_table;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int 			is_full;
	pthread_t		thread;
	long long		last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				no_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				simulation_running;
	int				num_each_philo_must_eat;
	int				finished_philos;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	simulation_lock;
	pthread_mutex_t	finished_lock;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_table;

void		start_simulation(int argc, char **argv);
void		create_thread(t_table	*table);
void		cleanup_simulation(t_table *table);
void		init_forks(t_table *table);
void		init_table(t_table *table);
void		init_philo(t_table *table);
void		one_philo(t_philo *philo, t_table *table);
void		philo_eat(t_philo *philo, t_table *table);
void		philo_no_odd_even(t_philo *philo, t_table *table);
void		*philosopher_routine(void *arg);
void		philo_eaten_enough(t_table *table);
void		check_philo_status(t_table *table, int i);
void		*monitor_philosophers(void *arg);
void		print_action(t_table *table, int id, char *action);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isnum(char	*c);
int			check_input(int argc, char **argv);
long long	current_time(void);
int			ft_atoi(const char *nptr);

#endif
