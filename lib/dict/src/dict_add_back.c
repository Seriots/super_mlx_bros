/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:50:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/09 20:13:03 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

static void	dict_modify(t_dict *elem, t_dict *new, void free_key(void *),
	void free_value(void *))
{
	t_dict	*next;
	t_dict	*previous;

	next = elem->next;
	previous = elem->previous;
	new->next = next;
	new->previous = previous;
	if (next)
		next->previous = new;
	if (previous)
		previous->next = new;
	if (free_key && elem->key)
		free_key(elem->key);
	if (free_value && elem->value)
		free_value(elem->value);
	free(elem);
}

void	dict_add_back(t_dict **dict, t_dict *new, void free_key(void *),
	void free_value(void *))
{
	t_dict	*copy;
	t_dict	*search;

	if (!dict || !new)
		return ;
	if (*dict == 0)
	{
		*dict = new;
		return ;
	}
	*dict = dict_get_first(*dict);
	search = dict_getelem_key(*dict, new->key);
	if (!search)
	{
		copy = dict_get_last(*dict);
		copy->next = new;
		new->previous = copy;
	}
	else
	{
		if (search->previous == 0)
			*dict = new;
		dict_modify(search, new, free_key, free_value);
	}
}
