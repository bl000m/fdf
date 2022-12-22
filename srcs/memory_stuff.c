/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:47:12 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/22 18:07:07 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	**allocate_values(int x_max, int y_max)
{
	t_fdf	**values;

	values = NULL;
	values = malloc(sizeof(t_fdf *) * y_max + 1);
	if (!*values)
		return (NULL);
	while (y_max > 0)
	{
		values[--y_max] = malloc(sizeof(t_fdf) * x_max + 1);
		if (!values[y_max])
		{
			free_all(values);
			return (NULL);
		}
	}
	return (values);
}

void	free_all(t_fdf **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return ;
}
