/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:07:20 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/11 01:22:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dict.h"
#include "../include/libft.h"

static t_dict	*dict_swap(t_dict *first, t_dict *second)
{
	t_dict	*next;
	t_dict	*previous;

	next = second->next;
	previous = first->previous;
	first->next = second->next;
	second->previous = first->previous;
	first->previous = second;
	second->next = first;
	if (next)
		next->previous = first;
	if (previous)
		previous->next = second;
	return (second);
}

void	dict_sort(t_dict **dict)
{
	t_dict	*copy;

	if (!dict || !*dict)
		return ;
	copy = *dict;
	while (copy->next)
	{
		if (ft_strncmp(copy->key, copy->next->key,
				ft_strlen(copy->key) + 1) > 0)
		{
			copy = dict_swap(copy, copy->next);
			copy = dict_get_first(copy);
		}
		else
			copy = copy->next;
	}
	*dict = dict_get_first(copy);
}
