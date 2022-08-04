/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:40:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/09 20:35:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/dict.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

void	dict_append(t_dict **dict1, t_dict **dict2)
{
	t_dict	*last;
	t_dict	*first;

	if (!dict1 || !dict2)
		return ;
	if (!*dict2)
		return ;
	if (!*dict1)
		*dict1 = *dict2;
	else
	{
		last = dict_get_last(*dict1);
		first = dict_get_first(*dict2);
		last->next = first;
		first->previous = last;
		*dict1 = dict_get_first(*dict1);
	}
}
