/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:28:59 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/20 15:33:19 by mpagani          ###   ########lyon.fr   */
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
	t_values	*coordinates;
	char		*line;
	int			**values;
	int			index;
	int			line_number;
	int			fd;

	index = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		while (line)
		{
			line = get_next_line(fd);
			*values = ft_split(line, ' ');
			while (values[index++])
				add_node_back(&coordinates, new_node(index, line_number, ft_atoi(values[index])));
			line_number++;
		}
	}
}

t_values	*new_node(int x, int y, int z)
{
	t_values	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (!new_elem)
		return (NULL);
	new_elem->x = x;
	new_elem->y = y;
	new_elem->z = z;
	new_elem->next = NULL;
	return (new_elem);
}

void	add_node_back(t_values **node, t_values *new)
{
	if (node == NULL)
		return ;
	if (*node == NULL)
		*node = new;
	else
		node_last(*node)->next = new;
}

t_values	*node_last(t_values *node)
{
	t_values	*ptr;

	ptr = node;
	if (ptr == NULL)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}
