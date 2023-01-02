/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:54:17 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 10:20:05 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	arr_len(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

float	highest(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

int	lowest(int a, int b)
{
	if (!a || !b)
		return (0);
	if (a < b)
		return (a);
	else
		return (b);
}

float	is_neg(float p)
{
	if (p < 0)
		return (-p);
	else
		return (p);
}

int	ft_words(char const *s, char c)
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
