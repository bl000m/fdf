/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:54:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/24 12:54:56 by mpagani          ###   ########lyon.fr   */
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
