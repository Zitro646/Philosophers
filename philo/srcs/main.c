/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:08:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/17 14:27:13 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//gcc main -pthread
/*atexit(leaks);
void	leaks(void)
{
	system("leaks -q philo");
}
*/

int	main(int argc, char **argv)
{
	t_philo	*data;

	if (error_control(argc, argv) != 1)
		return (0);
	data = declare_struct(argc, argv);
	start_thread(data);
	leaks_control(data);
}
