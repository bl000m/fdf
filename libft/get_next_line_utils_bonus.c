/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpagani <mpagani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:37:26 by mpagani           #+#    #+#             */
/*   Updated: 2022/12/10 12:14:01 by mpagani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_eol(t_list *record)
{
	int		i;
	t_list	*ptr;

	if (!record)
	{
		return (0);
	}
	i = 0;
	ptr = ft_lstlast(record);
	while (ptr->content[i] != '\0')
	{
		if (ptr->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_pattern(t_list **lst, char *buffer, int characters)
{
	t_list	*ptr;
	t_list	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(*new));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (characters + 1));
	if (!new->content)
		return ;
	while (buffer[i] && i < characters)
	{
		new->content[i] = buffer[i];
		i++;
	}
	new->content[i] = '\0';
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}

int	ft_line_size(t_list *record)
{
	int	len;
	int	i;

	len = 0;
	while (record)
	{
		i = 0;
		while (record->content[i] != '\0')
		{
			if (record->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		record = record->next;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	if (ptr == NULL)
		return (NULL);
	while (ptr && ptr->next)
		ptr = ptr->next;
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
