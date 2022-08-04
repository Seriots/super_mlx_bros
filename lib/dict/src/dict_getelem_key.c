/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_getelem_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:29:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/04 17:48:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "ft.h"

t_dict	*dict_getelem_key(t_dict *dict, void *key)
{
	if (!dict || !key)
		return (0);
	dict = dict_get_first(dict);
	while (dict && ft_strncmp(dict->key, key, ft_strlen(key) + 1) != 0)
		dict = dict->next;
	return (dict);
}
