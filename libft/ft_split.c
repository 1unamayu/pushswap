/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:56:49 by xamayuel          #+#    #+#             */
/*   Updated: 2021/11/16 17:18:13 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * NAME: ft_strsplit()
 * 
 * DESCRIPTION:
 * 		Allocates with malloc and return fresh array of strings obtained by
 * 		spliting the string s usign the character c as delimiter.
 * 		The last string of the array is NULL.
 * 
 * PARAMS:
 * 		@param s: string to be splitted.
 * 		@param c: delimiter character. 
 * 
 * RETURN:
 * 		Fresh array of strings
 */
static int	count_words(const char *str, char c);
static char	*word_dup(const char *str, int start, int finish);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || split == NULL )
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (split);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	if (str == 0)
		return (0);
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
		{
			trigger = 0;
		}
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}
