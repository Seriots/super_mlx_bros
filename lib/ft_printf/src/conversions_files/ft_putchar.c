/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:45:23 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:19 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversions.h"
#include "ft_printf.h"

int	ft_check_putchar(t_arg elem, char c)
{
	elem.min_champs -= ft_check_flags_putchar(elem, c, 0);
	return (ft_check_flags_putchar(elem, c, 1));
}

int	ft_check_flags_putchar(t_arg elem, char c, int print)
{
	int	i;

	i = 0;
	if (elem.f_minus == 0)
	{
		if (print)
			i += ft_print_minchamps(elem);
		i += ft_putchar(c, print);
	}
	else
	{
		i += ft_putchar(c, print);
		if (print)
			i += ft_print_minchamps(elem);
	}
	return (i);
}

int	ft_putchar(char c, int print)
{
	if (print)
		write(1, &c, 1);
	return (1);
}
