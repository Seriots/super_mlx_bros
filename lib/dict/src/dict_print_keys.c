/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_print_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:43:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/08 22:52:43 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "ft_printf.h"

void	dict_print_keys(t_dict *dict)
{
	if (!dict)
		return ;
	while (dict)
	{
		ft_printf("%s\n", dict->key);
		dict = dict->next;
	}
}
