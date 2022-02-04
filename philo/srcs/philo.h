/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:07:49 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/04 17:49:07 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>	
# include <unistd.h>
# include <sys/time.h>

typedef struct philo
{
	pthread_t		id_threats;
	int				id;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_must_eat;
	pthread_mutex_t	*forks;
}t_philo;

typedef struct table
{
	t_philo		*philosophers;
	int			number_of_philosophers;

}t_table;

void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
int		ft_count_forks(pthread_mutex_t *list);

t_table	declare_table(int argc, char **argv);
void	start_thread(t_table data);

#endif