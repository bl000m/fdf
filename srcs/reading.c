/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:49:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/27 15:29:43 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	**read_map(char *file_map, t_global *global)
{
	t_fdf	**values;
	int		y;

	values = NULL;
	y = 0;
	get_size(file_map, global);
	values = malloc(sizeof(t_fdf *) * (global->y_max + 1));
	if (!values)
		return (NULL);
	while (y < global->y_max)
	{
		values[y] = malloc(sizeof(t_fdf) * (global->x_max + 1));
		if (!values[y])
		{
			free_all(values);
			return (NULL);
		}
		y++;
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
	global->y_max = get_values(file_map, 'y');
	fd = open_file_map(file_map);
	while (y < global->y_max)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_points(line, y, values);
		free(line);
		y++;
	}
	values[y] = NULL;
	close(fd);
	// display_z(values, (*global->map)->x_max, global->y_max);
}
