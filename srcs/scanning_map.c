/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:57:40 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/27 15:28:44 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	open_file_map(char *file_map)
{
	int		fd;

	fd = open(file_map, O_RDONLY);
	check_error(fd);
	return (fd);
}

int	get_values(char *file_map, char c)
{
	int	fd;

	fd = open_file_map(file_map);
	if (c == 'x')
		return (get_x_max(fd));
	else if (c == 'y')
		return (get_y_max(fd));
	else
		return (-1);
	close(fd);
}

int	get_x_max(int fd)
{
	int		x_max;
	char	*line;

	line = get_next_line(fd);
	x_max = ft_words(line, ' ');
	free(line);
	return (x_max);
}

// tbc if to be free
int	get_y_max(int fd)
{
	int		y_max;
	char	*line;

	y_max = 0;
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		if (!line)
			break ;
		y_max++;
	}
	return (y_max);
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

void	get_size(char *file_map, t_global *global)
{
	int		x_max;
	int		y_max;

	x_max = get_values(file_map, 'x');
	y_max = get_values(file_map, 'y');
	if (x_max == -1 || y_max == -1)
		return ;
	global->x_max = x_max;
	global->y_max = y_max;
	ft_printf("test %d - %d\n", x_max, y_max);
}
