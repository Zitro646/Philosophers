/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:35:34 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/17 13:56:58 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

useconds_t	time_diff(useconds_t present, useconds_t past)
{
	return (present - past);
}

void	ft_usleep(useconds_t time, t_table *table)
{
	useconds_t	start;
	useconds_t	mytime;

	start = ft_get_time();
	mytime = ft_get_time();
	pthread_mutex_lock(table->live);
	while ((mytime - start) < time && table->alive)
	{
		pthread_mutex_unlock(table->live);
		usleep(500);
		mytime = ft_get_time();
		pthread_mutex_lock(table->live);
	}
	pthread_mutex_unlock(table->live);
}
