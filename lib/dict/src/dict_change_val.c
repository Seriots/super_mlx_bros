/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_change_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:34:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/09 20:12:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

void	dict_changeval(t_dict **dict, void *key, void *value,
	void free_value(void *))
{
	t_dict	*elem;

	if (!dict || !key || !value)
		return ;
	elem = dict_getelem_key(*dict, key);
	if (!elem)
		return ;
	if (free_value && elem->value)
		free_value(elem->value);
	elem->value = value;
}
