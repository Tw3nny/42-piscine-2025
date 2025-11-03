/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 14:21:56 by matiguti          #+#    #+#             */
/*   Updated: 2025/09/30 13:22:53 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strbigcat(char **strs, char *str, int size, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		str[k++] = strs[i][j++];
		j = 0;
		while ((i < size - 1) && sep[j] != '\0')
			str[k++] = sep[j++];
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s1;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (size == 0)
	{
		s1 = malloc(1);
		s1[0] = '\0';
		return (s1);
	}
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	len = len + ft_strlen(sep) * (size - 1);
	s1 = (char *)malloc((sizeof(char)) * (len + 1));
	if (!s1)
		return (NULL);
	s1 = ft_strbigcat(strs, s1, size, sep);
	return (s1);
}
/*
int	main(void)
{
	char *strs[] = {"ue", "ue", "sa", "dit", "quoi",};
	char *sep = " ";
	char *res = ft_strjoin(0, strs, sep);
	printf("%s", res);
	free(res);
	return (0);
}*/
