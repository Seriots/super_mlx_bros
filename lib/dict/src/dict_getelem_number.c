/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_getelem_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:20:46 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/08 22:48:17 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict	*dict_getelem_number(t_dict *dict, size_t n)
{
	size_t	i;

	if (!dict)
		return (0);
	dict = dict_get_first(dict);
	i = 0;
	while (i < n && dict)
	{
		dict = dict->next;
		i ++;
	}
	return (dict);
}
