/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:47:12 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/29 16:49:53 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	allocate_values(t_fdf **values, t_global *global)
// {
// 	values = malloc(sizeof(t_fdf *) * (*global->map)->y_max + 1);
// 	if (!values)
// 		return ;
// 	while ((*global->map)->y_max > 0)
// 	{
// 		values[--(*global->map)->y_max] = malloc(sizeof(t_fdf)
// 				* (*global->map)->x_max + 1);
// 		if (!values[(*global->map)->y_max])
// 		{
// 			free_all(values);
// 			return ;
// 		}
// 	}
// }

void	free_all(t_fdf **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
	return ;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return ;
}

void	free_exit(t_global *global)
{
	if (global->map)
		free(global->map);
}
