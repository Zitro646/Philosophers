/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:31:48 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/10 18:45:50 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_alive(t_philo *philo)
{
	philo->time_now = ft_get_time();
	if ((philo->time_now - philo->time_last_meal) >= philo->table->time_to_die \
		&& philo->table->alive)
	{
		philo->table->alive = 0;
		printf("%u - El filosofo %i ha muerto :(\n", \
			ft_get_time() - philo->table->time_start, philo->id);
	}
	if (philo->table->alive)
		return (1);
	else
		philo->table->alive = 0;
	return (0);
}

int	check_keep_eating(t_philo *philo)
{
	//printf("Chequea las vecces que comemos\n");
	if (philo->table->number_of_times_must_eat == -1)
		return (1);
	if (philo->times_has_eaten < philo->table->number_of_times_must_eat)
		return (1);
	return (0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (check_alive(philo))
		printf("%u - El filosofo %i coge el tenedor izquierdo\n", \
				(ft_get_time() - philo->table->time_start), philo->id);
	pthread_mutex_lock(philo->r_fork);
	if (check_alive(philo))
		printf("%u - El filosofo %i coge el tenedor derecho\n", \
			(ft_get_time() - philo->table->time_start), philo->id);
	if (check_alive(philo))
	{
		philo->time_last_meal = ft_get_time();
		printf("%u - El filosofo %i empieza a comer\n", \
			(ft_get_time() - philo->table->time_start), philo->id);
		ft_usleep(philo->table->time_to_eat);
	}
	check_alive(philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	philo->times_has_eaten++;
}

void	*metodo_filosofo(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	philo->time_last_meal = philo->table->time_start;
	if (philo->id % 2 == 0)
		ft_usleep(100);
	while (check_alive(philo))
	{
		if (check_alive(philo))
		{
			eat(philo);
			if (check_alive(philo))
			{
				printf("%u - El filosofo %i empieza a dormir\n", \
					(ft_get_time() - philo->table->time_start), philo->id);
				ft_usleep(philo->table->time_to_sleep);
				if (check_alive(philo))
					printf("%u - El filosofo %i piensa\n", \
						(ft_get_time() - philo->table->time_start), philo->id);
			}
			if (check_keep_eating(philo) != 1)
				break ;
		}
	}
	return (arg);
}
