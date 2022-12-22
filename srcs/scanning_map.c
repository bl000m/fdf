/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanning_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:57:40 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/22 16:31:11 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
