/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:35:34 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/16 14:58:11 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(useconds_t time, t_table *table)
{
	useconds_t	start;
	useconds_t	mytime;

	start = ft_get_time();
	mytime = ft_get_time();
	while ((mytime - start) < time && table->alive)
	{
		usleep(500);
		mytime = ft_get_time();
	}
}
