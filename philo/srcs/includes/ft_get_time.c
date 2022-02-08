/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:30:32 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/08 15:36:21 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

useconds_t	ft_get_time(void)
{
	useconds_t		current_time;
	struct timeval	start;

	gettimeofday(&start, NULL);
	current_time = (start.tv_sec) * 1000 + (start.tv_usec) / 1000;
	return (current_time);
}
