/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:46:14 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:19 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversions.h"
#include "ft_printf.h"

int	ft_check_putnbrunsigned(t_arg elem, unsigned int n)
{
	int	i;

	if (n == 0 && elem.precision_detected == 1 && elem.precision == 0)
	{
		elem.min_champs -= elem.precision;
		i = ft_print_minchamps(elem);
		i += ft_print_precision(elem);
		return (i);
	}
	i = ft_check_flags_putnbr_unsigned(elem, n, 0);
	elem.precision -= i;
	if (elem.precision > 0)
		elem.min_champs -= i + elem.precision;
	else
		elem.min_champs -= i;
	return (ft_check_flags_putnbr_unsigned(elem, n, 1));
}

int	ft_check_flags_putnbr_unsigned(t_arg elem, unsigned int n, int print)
{
	int	i;

	i = 0;
	if (elem.f_minus == 0)
	{
		if (print)
			i += ft_print_minchamps(elem);
		if (print)
			i += ft_print_precision(elem);
		ft_putnbr_unsigned(n, &i, print);
	}
	else
	{
		if (print)
			i += ft_print_precision(elem);
		ft_putnbr_unsigned(n, &i, print);
		if (print)
			i += ft_print_minchamps(elem);
	}
	return (i);
}

void	ft_putnbr_unsigned(unsigned int n, int *i, int print)
{
	if (n > 9)
		ft_putnbr_unsigned(10, i, print);
	if (print)
		ft_putchar((char)((n % 10) + 48), print);
	*i += 1;
}
