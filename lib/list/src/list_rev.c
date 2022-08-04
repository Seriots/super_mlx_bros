/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:48:26 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/16 10:24:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../include/list.h"

void	list_change_next(t_list **lst, size_t size)
{
	size_t	i;
	t_list	*current;
	t_list	*next;

	i = 1;
	current = *lst;
	next = current->next;
	while (i < size && next)
	{
		current = next;
		next = current->next;
		i ++;
	}
	if (next)
		next->next = current;
}

void	list_rev(t_list **l)
{
	t_list	*first;
	t_list	*last;
	size_t	size;

	if (!l || !*l)
		return ;
	if (!(*l)->next)
		return ;
	first = *l;
	last = list_last(first);
	size = list_size(first);
	while (size > 1)
	{
		list_change_next(l, size - 1);
		size --;
	}
	first->next = 0;
	*l = last;
	return ;
}
