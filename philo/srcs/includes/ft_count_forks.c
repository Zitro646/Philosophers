/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:22:47 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/04 13:30:23 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_count_forks(pthread_mutex_t *list)
{
	int	i;

	i = 0;
	if (list != 0)
	{
		while (&list[i] != 0)
		{
			i++;
			printf("Cuenta %i \n",i);
		}
	}
	return (i);
}
