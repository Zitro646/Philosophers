/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:41:13 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/02 16:32:52 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	declare_struct(int argc, char **argv)
{
	t_philo	data;

	data.number_of_times_each_philosopher_must_eat = -1;
	data.number_of_philosophers = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	ft_calloc(sizeof(pthread_t), data.number_of_philosophers);
	//printf("Datos introducidos \nNº philosophos : %i \nTime to die : %i \nTime to eat : %i\nTime to sleep : %i\nNumero de veces que deben comer : %i\n",data.number_of_philosophers,data.time_to_die,data.time_to_eat,data.time_to_sleep,data.number_of_times_each_philosopher_must_eat);
	return (data);
}
