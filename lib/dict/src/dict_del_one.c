/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_del_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:57:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/09 20:11:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

void	dict_delone(t_dict **dict, t_dict *elem, void free_key(void *),
	void free_value(void *))
{
	t_dict	*copy;
	t_dict	*next;
	t_dict	*previous;

	if (!*dict || !elem)
		return ;
	copy = *dict;
	while (copy && copy != elem)
		copy = copy->next;
	if (!copy)
		return ;
	next = copy->next;
	previous = copy->previous;
	if (free_key && elem->key)
		free_key(elem->key);
	if (free_value && elem->value)
		free_value(elem->value);
	if (previous)
		previous->next = next;
	if (next)
		next->previous = previous;
	if (!copy->previous)
		*dict = dict_get_first(copy->next);
	free(copy);
}
