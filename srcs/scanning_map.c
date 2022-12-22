/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:57:40 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/22 18:06:25 by mpagani          ###   ########lyon.fr   */
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
	char	**values;

	values = ft_split(get_next_line(fd), ' ');
	x_max = arr_len(values);
	free(values);
	return (x_max);
}

// tbc if to be free
int	get_y_max(int fd)
{
	int	y_max;

	y_max = 0;
	while (get_next_line(fd))
		y_max++;
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
		free(single_points[x]);
		x++;
	}
}
