/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_print_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:44:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/06/08 22:52:52 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "ft_printf.h"

void	dict_print_values(t_dict *dict)
{
	if (!dict)
		return ;
	while (dict)
	{
		ft_printf("%s\n", dict->value);
		dict = dict->next;
	}
}
