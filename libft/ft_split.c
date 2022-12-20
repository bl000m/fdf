/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:52:20 by mpagani           #+#    #+#             */
/*   Updated: 2022/11/18 08:56:43 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	words;
	int	on_off;
	int	i;

	words = 0;
	on_off = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && on_off == 0)
		{
			on_off = 1;
			words++;
		}
		else if (s[i] == c)
			on_off = 0;
		i++;
	}
	return (words);
}

static void	ft_free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return ;
}

static void	ft_split2(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (index < 0 && s[i] != c)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			result[j] = malloc(sizeof(char *) * ((i - index) + 1));
			if (!result[j])
				return (ft_free_all(result));
			ft_strlcpy(result[j], (char *)&s[index], (i - index) + 1);
			index = -1;
			j++;
		}
		i++;
	}
	result[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(*result) * (ft_words(s, c) + 1));
	if (!result)
		return (NULL);
	ft_split2(result, s, c);
	return (result);
}
