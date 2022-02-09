/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:07:49 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/09 13:49:44 by mortiz-d         ###   ########.fr       */
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
	int				number_of_philosophers;
	int				number_of_times_must_eat;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
	pthread_mutex_t	*forks;

}t_table;

typedef struct philo
{
	pthread_t		id_threats;
	int				id;
	t_table			*table;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	useconds_t		time_start;
	useconds_t		time_now;
	useconds_t		time_last_meal;
}t_philo;

void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
int			ft_count_forks(pthread_mutex_t *list);
void		ft_usleep(useconds_t time);
useconds_t	ft_get_time(void);

t_philo		*declare_struct(int argc, char **argv);
void		start_thread(t_philo *data);
void		*metodo_filosofo(void *arg);
void		leaks_control(t_philo *data);
#endif