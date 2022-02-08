/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 10:35:34 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/08 15:36:13 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_usleep(useconds_t time)
{
	useconds_t	start;
	useconds_t	mytime;

	start = ft_get_time();
	mytime = ft_get_time();
	while ((mytime - start) < time)
	{
		usleep(10);
		mytime = ft_get_time();
	}
}
