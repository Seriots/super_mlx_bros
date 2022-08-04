/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:47:18 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/08 22:48:17 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict	*dict_get_last(t_dict *dict)
{
	if (!dict)
		return (0);
	while (dict->next != 0)
		dict = dict->next;
	return (dict);
}
