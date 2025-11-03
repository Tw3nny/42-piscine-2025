/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matiguti <matiguti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:16:04 by matiguti          #+#    #+#             */
/*   Updated: 2025/09/29 10:28:25 by matiguti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// check separator
int	ft_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

// compte les mots
int	ft_count_words(char *str, char *charset)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_separator(str[i], charset) == 1)
		{
			in_word = 0;
		}
		else
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		i++;
	}
	return (count);
}

// check la taille des mots
int	ft_words_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_separator(str[i], charset) == 0)
	{
		i++;
	}
	return (i);
}

// copy les mots (strcpy)
char	*ft_copy_word(char *str, int len)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		len;
	char	**result;

	if (str == NULL)
		return (NULL);
	result = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] && ft_separator(str[i], charset) == 1)
			i++;
		if (str[i])
		{
			len = ft_words_len(&str[i], charset);
			result[j++] = ft_copy_word(&str[i], len);
			i += len;
		}
	}
	result[j] = NULL;
	return (result);
}
/*
int main(void)
{
    char *str = "ue, ue; sa/ dit: quoi;";
    char *charset = ",;:";
    char **result;
    int i;

    result = ft_split(str, charset);

    if (result)
    {
        i = 0;
        while (result[i])
        {
            printf("%s", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    return (0);
}*/
