/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:34:26 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/02 15:37:28 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*aux1;

	aux1 = s;
	while (n > 0)
	{
		*aux1 = '\0';
		aux1++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*aux1;

	aux1 = malloc(count * size);
	if (aux1 == NULL)
		return (0);
	ft_bzero(aux1, (count * size));
	return (aux1);
}
