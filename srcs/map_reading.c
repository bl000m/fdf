/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:49:17 by mpagani           #+#    #+#             */
/*   Updated: 2023/01/02 14:31:49 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	read_map(char *file_map, t_global *global)
{
	int		y;

	y = 0;
	get_size(file_map, global);
	global->map = malloc(sizeof(t_fdf *) * (global->y_max + 1));
	if (!global->map)
	{
		free_all(global->map);
		exit(1);
	}
	while (y < global->y_max)
	{
		global->map[y] = malloc(sizeof(t_fdf) * (global->x_max + 1));
		if (!global->map[y])
		{
			free_all(global->map);
			exit (1);
		}
		y++;
	}
	create_3d(file_map, global);
}

void	create_3d(char *file_map, t_global *global)
{
	char	*line;
	int		fd;
	int		y;

	fd = 0;
	y = 0;
	fd = open_file_map(file_map);
	while (y < global->y_max)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		get_points(line, y, global->map);
		free(line);
		y++;
	}
	global->map[y] = NULL;
	close(fd);
}

void	get_points(char *line, int y, t_fdf **values)
{
	int		x;
	char	**single_points;

	x = 0;
	single_points = ft_split(line, ' ');
	while (single_points[x])
	{
		values[y][x].x = x;
		values[y][x].y = y;
		values[y][x].z = ft_atoi(single_points[x]);
		values[y][x].last = 0;
		free(single_points[x]);
		x++;
	}
	free(single_points);
	values[y][--x].last = 1;
}
