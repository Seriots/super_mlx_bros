/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:22:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/08 22:48:17 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

size_t	dict_size(t_dict *dict)
{
	size_t	i;

	if (!dict)
		return (0);
	i = 0;
	while (dict)
	{
		i++;
		dict = dict->next;
	}
	return (i);
}
