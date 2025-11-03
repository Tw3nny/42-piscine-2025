/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:59:17 by matiguti          #+#    #+#             */
/*   Updated: 2025/09/30 17:06:19 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	j;

	i = 1;
	j = nb;
	if (power < 0)
		return (0);
	if (power == 0 || nb == 0)
		return (1);
	while (i < power)
	{
		nb = nb * j;
		i++;
	}
	return (nb);
}
/*
int	main(void)
{
	int nb = 4;
	int power = 4;
	printf("%d", ft_iterative_power(nb, power));
	return (0);
}*/
