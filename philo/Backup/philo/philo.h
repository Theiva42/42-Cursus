/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thkumara <thkumara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:20:01 by thkumara          #+#    #+#             */
/*   Updated: 2025/03/27 16:44:02 by thkumara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_table;

typedef struct s_philo
{
	int				id;
	int				eat_count;
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
	int				num_times_each_philosopher_must_eat;
	int				finished_philosophers;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	simulation_lock;
	pthread_mutex_t	finished_lock;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_table;

void		start_simulation(int argc, char **argv);
void		print_action(t_table *table, int id, char *action);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isnum(char	*c);
int			check_input(int argc, char **argv);
long long	current_time(void);

#endif
