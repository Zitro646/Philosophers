/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:31:48 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/17 13:57:21 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_order(t_philo *philo, char *command, useconds_t time)
{
	pthread_mutex_lock(philo->table->print);
	pthread_mutex_lock(philo->table->live);
	if (philo->table->alive)
	{
		printf ("%u ", time);
		printf ("%i ", philo->id);
		printf ("%s\n", command);
	}
	pthread_mutex_unlock(philo->table->live);
	pthread_mutex_unlock(philo->table->print);
}

static int	check_keep_eating(t_philo *philo)
{
	if (philo->table->number_of_times_must_eat == -1)
		return (1);
	if (philo->times_has_eaten < philo->table->number_of_times_must_eat)
		return (1);
	return (0);
}

static int	check_philo_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->table->live);
	if (philo->table->alive == 1)
	{
		pthread_mutex_unlock(philo->table->live);
		return (1);
	}
	pthread_mutex_unlock(philo->table->live);
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_order(philo, "has taken a fork",
		time_diff(ft_get_time(), philo->table->time_start));
	pthread_mutex_lock(philo->r_fork);
	print_order(philo, "has taken a fork",
		time_diff(ft_get_time(), philo->table->time_start));
	pthread_mutex_lock(&philo->meal_check);
	philo->time_last_meal = ft_get_time();
	philo->times_has_eaten++;
	pthread_mutex_unlock(&philo->meal_check);
	print_order(philo, "is eating", \
		time_diff(ft_get_time(), philo->table->time_start));
	ft_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*metodo_filosofo(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->table->start);
	pthread_mutex_unlock(philo->table->start);
	if (philo->id % 2 == 0)
		ft_usleep(1, philo->table);
	while (check_philo_alive(philo))
	{
		if (philo->l_fork != philo->r_fork)
		{
			eat(philo);
			print_order(philo, "is sleeping", \
				time_diff(ft_get_time(), philo->table->time_start));
			ft_usleep(philo->table->time_to_sleep, philo->table);
			print_order(philo, "is thinking", \
				time_diff(ft_get_time(), philo->table->time_start));
			if (check_keep_eating(philo) != 1)
				break ;
		}
	}
	return (arg);
}
