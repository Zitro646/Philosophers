/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:02:37 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/17 13:52:29 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	leaks_control(t_philo *data)
{
	t_table	*table;
	int		i;
	int		max;

	max = data->table->number_of_philosophers;
	table = data->table;
	i = 0;
	free(table->forks);
	free(table->print);
	free(table->live);
	free(table->start);
	free(table);
	while (i < max)
	{
		pthread_mutex_destroy(data[i].r_fork);
		i++;
	}
	free(data);
}
