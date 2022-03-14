/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:07:49 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/14 12:22:03 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>	
# include <unistd.h>
# include <sys/time.h>

typedef struct table
{
	int				alive;
	int				all_eaten;
	int				number_of_philosophers;
	int				number_of_times_must_eat;
	useconds_t		time_start;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*meal_check;
	pthread_mutex_t	*live;

}t_table;

typedef struct philo
{
	pthread_t		id_threats;
	pthread_t		id_live;
	int				id;
	t_table			*table;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	meal_check;
	useconds_t		time_now;
	useconds_t		time_last_meal;
	int				times_has_eaten;
}t_philo;

void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
void		ft_usleep(useconds_t time, t_table *table);
useconds_t	ft_get_time(void);

void		print_order(t_philo *philo, char *command, useconds_t time);
t_philo		*declare_struct(int argc, char **argv);
void		start_thread(t_philo *data);
void		*metodo_filosofo(void *arg);
int			everybody_ate(t_philo	*data);
int			check_keep_eating(t_philo *philo);
void		leaks_control(t_philo *data);
int			error_control(int argc, char **argv);
#endif