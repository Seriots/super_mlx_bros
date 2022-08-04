/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:43:53 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:20 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_print_minchamps(t_arg elem)
{
	int	i;

	i = 0;
	while (i < elem.min_champs)
	{
		if (elem.f_zero == 1 && elem.f_minus == 0 && elem.attribut != 'c'
			&& elem.attribut != 's' && elem.precision_detected == 0)
			write(1, "0", 1);
		else
			write (1, " ", 1);
		i ++;
	}
	return (i);
}

int	ft_print_precision(t_arg elem)
{
	int	i;

	i = 0;
	while (i < elem.precision)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}
