/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:54:55 by matiguti          #+#    #+#             */
/*   Updated: 2025/09/15 10:18:02 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{	
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] >= 32 && \
		(unsigned char)str[i] <= 127)
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "ue ue sa dit quoi";
	printf("%d", ft_str_is_printable(str));
	return (0);
}*/
