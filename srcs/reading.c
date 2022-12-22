/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:49:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/22 16:56:18 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
* create node
* call get_x to assign x to node
* call get_y to assign y to node
* call get_z to assign z to node
*/
t_fdf	**read_map(char *file_map)
{
	int		x_max;
	int		y_max;
	// t_fdf	**values;

	x_max = get_values(file_map, 'x');
	y_max = get_values(file_map, 'y');
	if (x_max == -1 || y_max == -1)
		return (NULL);
	ft_printf("x_max = %i\n", x_max);
	ft_printf("y_max = %i\n", y_max);
	// values = allocate_values(x_max, y_max);
	// while (y_max > 0)
	// {
	// 	values = ft_split(get_next_line(fd), ' ');
	// 	x_max = arr_len(ft_split(get_next_line(fd), ' '));
	// 	ft_printf("x_max = %i\n", x_max);
	// 	free(values);
	// 	ft_printf("y_max = %i\n", y_max);
	// 	y_max--;
	// }
	return (NULL);
}
