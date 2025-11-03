/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:16:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/23 10:57:12 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	k;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	k = 0;
	if (size <= size_dest)
	{
		return (size + size_src);
	}
	while (src[k] != '\0' && k < (size - size_dest - 1))
	{
		dest[size_dest + k] = src[k];
		k++;
	}
	dest[size_dest + k] = '\0';
	return (size_dest + size_src);
}
/*
int	main(void)
{
	char	dest[] = "ue ue";
	char	src[] = " sa dit quoi";
	int	size = 7;
	printf("%d\n", ft_strlcat(dest, src, size));
	printf("%s", dest);
	return (0);
}*/
