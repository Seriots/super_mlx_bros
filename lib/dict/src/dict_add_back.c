/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:50:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/08 14:37:18 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

void	dict_add_back(t_dict **dict, t_dict *new)
{
	t_dict	*copy;

	if (!dict || !new)
		return ;
	if (*dict == 0)
	{
		*dict = new;
		return ;
	}
	copy = dict_get_last(*dict);
	copy->next = new;
	new->previous = copy;
}
