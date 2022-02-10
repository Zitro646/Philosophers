/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_method.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:31:48 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/10 13:34:20 by mortiz-d         ###   ########.fr       */
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
		printf("El filosofo %i ha muerto :(\n", philo->id);
	}
	if (philo->table->alive)
		return (1);
	else
		return (0);
}

void	eat_pairs(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	if (check_alive(philo))
	{
		printf("%u - El filosofo %i empieza a comer\n", \
			(philo->time_now - philo->table->time_start), philo->id);
		philo->time_last_meal = philo->time_now;
	}
	else
		philo->table->alive = 0;
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	eat_odds(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	if (check_alive(philo))
	{
		printf("%u - El filosofo %i empieza a comer\n", \
			(philo->time_now - philo->table->time_start), philo->id);
		philo->time_last_meal = philo->time_now;
	}
	else
		philo->table->alive = 0;
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*metodo_filosofo(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	philo->time_last_meal = philo->table->time_start;
	while (check_alive(philo))
	{
		if (philo->id % 2 == 0)
			eat_pairs(philo);
		else
			eat_odds(philo);
		if (philo->table->alive)
			ft_usleep(philo->table->time_to_sleep);
	}
	return (arg);
}

//printf("filosofo :%i -> (%u) >= %i\n", philo->id, 
//philo->time_now - philo->time_last_meal, philo->table->time_to_die);
//
//printf("El filosofo %i ha terminado\n", philo->id);
//
//printf("para el filosofo %i right : %p // left : %p\n", 
//philo->id,philo->r_fork,philo->l_fork);
//
//printf("Philo : %i \nTime to eat : %i\nTime to die : 
//%i\nTime to sleep : %i\n",philo->id,philo->time_to_eat,
//philo->time_to_die,philo->time_to_sleep);
//
//printf("(%li) >= %i\n", time_now - time_to_live, philo->time_to_die);
//
//printf("El filosofo %i ha muerto con un destiempo de %li :(\n",
//philo->id, time_now - time_to_live);
/*
void	*metodo_filosofo_pares(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	philo->time_start = ft_get_time();
	philo->time_last_meal = philo->time_start;
	//printf("Filosofo %i esta vivo? %i/1\n",philo->id ,*(philo->alive));
	while (philo->table->alive)
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
		philo->time_now = ft_get_time();
		if ((philo->time_now - philo->time_last_meal) >= philo->table->time_to_die)
			break ;
		printf("%u - El filosofo %i empieza a comer\n", (philo->time_now - philo->time_start), philo->id);
		ft_usleep(philo->table->time_to_eat);
		philo->time_last_meal = philo->time_now;
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		ft_usleep(philo->table->time_to_sleep);
	}
	if ((philo->time_now - philo->time_last_meal) >= philo->table->time_to_die)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		printf("El filosofo %i ha muerto :(\n",philo->id);
		philo->table->alive = 0;
	}
	return (arg);
}
*/

