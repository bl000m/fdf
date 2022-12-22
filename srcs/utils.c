/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:54:17 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/22 16:22:32 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	arr_len(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_fdf	*new_node(int x, int y, int z)
{
	t_fdf	*new_elem;

	new_elem = malloc(sizeof(*new_elem));
	if (!new_elem)
		return (NULL);
	new_elem->x = x;
	new_elem->y = y;
	new_elem->z = z;
	new_elem->next = NULL;
	return (new_elem);
}

t_fdf	*node_last(t_fdf *node)
{
	t_fdf	*ptr;

	ptr = node;
	if (ptr == NULL)
		return (NULL);
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	add_node_back(t_fdf **node, t_fdf *new)
{
	if (node == NULL)
		return ;
	if (*node == NULL)
		*node = new;
	else
		node_last(*node)->next = new;
}
