/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:41:37 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/08 22:48:17 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

t_dict	*dict_get_first(t_dict *dict)
{
	if (!dict)
		return (0);
	while (dict->previous != 0)
		dict = dict->previous;
	return (dict);
}
