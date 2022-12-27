/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:54:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/27 15:03:09 by mpagani          ###   ########lyon.fr   */
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

float	highest_delta(float x, float y)
{
	if (x > y)
		return (x);
	else
		return (y);
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

void	display_z(t_fdf *array[], int x_max, int y_max)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < y_max)
	{
		while (j < x_max)
		{
			ft_printf("%i(x)", array[i][j].x);
			ft_printf("%i(y)", array[i][j].y);
			ft_printf("%i(z), ", array[i][j].z);
			j++;
		}
		j = 0;
		i++;
	}
}
