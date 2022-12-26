/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:49:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/26 18:43:34 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	**read_map(char *file_map, t_global *global)
{
	t_fdf	**values;

	values = NULL;
	values = malloc(sizeof(t_fdf *) * (*global->map)->y_max + 1);
	if (!values)
		return (NULL);
	while ((*global->map)->y_max > 0)
	{
		values[--(*global->map)->y_max] = malloc(sizeof(t_fdf)
				* (*global->map)->x_max + 1);
		if (!values[(*global->map)->y_max])
		{
			free_all(values);
			return (NULL);
		}
	}
	create_list(file_map, global, values);
	return (values);
}

void	create_list(char *file_map, t_global *global, t_fdf **values)
{
	char	*line;
	int		fd;
	int		y;

	fd = 0;
	y = 0;
	(*global->map)->y_max = get_values(file_map, 'y');
	fd = open_file_map(file_map);
	while (y < (*global->map)->y_max)
	{
		line = get_next_line(fd);
		get_points(line, y, values);
		free(line);
		y++;
	}
	values[y] = NULL;
	close(fd);
	// display_z(values, (*global->map)->x_max, (*global->map)->y_max);
}
