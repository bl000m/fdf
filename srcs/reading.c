/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:49:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/23 11:26:58 by mpagani          ###   ########lyon.fr   */
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
	int		y;
	int		fd;
	t_fdf	**values;
	char	*line;

	fd = 0;
	y = 0;
	x_max = get_values(file_map, 'x');
	y_max = get_values(file_map, 'y');
	if (x_max == -1 || y_max == -1)
		return (NULL);
	values = allocate_values(x_max, y_max);
	fd = open_file_map(file_map);
	while (y < y_max)
	{
		line = get_next_line(fd);
		get_points(line, y, values);
		free(line);
		y++;
	}
	// display_z(values, x_max, y_max);
	return (values);
}
