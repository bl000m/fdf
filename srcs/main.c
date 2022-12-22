/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:28:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/22 16:54:33 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
	* = incertitudes
	What are we supposed to do ?
	1. open and read the map line by line => gnl, fd = map.fdf
	RENDERING
	2. convert each value of the map .fdf in coordinates (x, y, z)
	=> x(axis) = index of the nb in line (scanning horizontally)
	=> y(ordinate) = n. of line where the nb is (scanning vertically)
	=> z(altitude) = value of nb
	* y = 0 is the first  line
	split + atoi sur chaque charactere pour obtenir un array de struct (contenant x y z etc..)
	DISPLAY IMAGES
	3. load the MiniLibX via the Makefile to open a GUI (?)
	practice (https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
	4. create the wireframe model representation. How ?
		a. link points in segments => Bresenham's line ?
		b. sin and cos to make isometric projection
		c * ...
	5. code functions to execute EVENT:
	- ESC to close the window
	- click on the cross quit the program => what means ?
	BONUS PART ? is it worth it ?
	- add extra projection (Parallel or conic)
	- zoom in and out
	- rotate model


*/

int	main(int argc, char **argv)
{
	t_fdf	**converted_map;
	char	*file_map;

	if (argc == 2)
	{
		file_map = argv[1];
		converted_map = read_map(file_map);
	}
}

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
