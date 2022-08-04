/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:46:03 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:19 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversions.h"
#include "ft_printf.h"

int	ft_check_putnbr(t_arg elem, int n)
{
	int	i;
	int	minusmark;

	minusmark = 0;
	if (n == 0 && elem.precision_detected == 1 && elem.precision == 0)
	{
		elem.min_champs -= elem.precision;
		i = ft_print_minchamps(elem);
		i += ft_print_precision(elem);
		return (i);
	}
	i = ft_check_flags_putnbr(elem, n, 0);
	if (elem.f_space || elem.f_plus || n < 0)
		minusmark += 1;
	elem.precision -= i;
	if (elem.precision > 0)
		elem.min_champs -= i + elem.precision + minusmark;
	else
		elem.min_champs -= i + minusmark;
	return (ft_check_flags_putnbr(elem, n, 1));
}

void	ft_check_flags_putnbr2(int *i, t_arg elem, int n, int print)
{
	if (print && (elem.f_zero == 0 || elem.precision_detected == 1))
		*i += ft_print_minchamps(elem);
	if (elem.f_plus == 1)
	{
		if (print && n >= 0)
			write (1, "+", 1);
		if (n >= 0 && print)
			*i += 1;
	}
	else if (elem.f_space == 1)
	{
		if (print && n >= 0)
			write (1, " ", 1);
		if (n >= 0 && print)
			*i += 1;
	}
	if (print && n < 0)
		write(1, "-", 1);
	if (n < 0 && print)
		*i += 1;
	if (elem.f_zero == 1 && print && elem.precision_detected == 0)
		*i += ft_print_minchamps(elem);
	if (print)
		*i += ft_print_precision(elem);
	ft_putnbr(n, i, print);
}

void	ft_check_flags_putnbr3(int *i, t_arg elem, int n, int print)
{
	if (elem.f_plus == 1)
	{
		if (print && n >= 0)
			write (1, "+", 1);
		if (n >= 0 && print)
			*i += 1;
	}
	else if (elem.f_space == 1)
	{
		if (print && n >= 0)
			write (1, " ", 1);
		if (n >= 0 && print)
			*i += 1;
	}
	if (print && n < 0)
		write(1, "-", 1);
	if (n < 0 && print)
		*i += 1;
	if (print)
		*i += ft_print_precision(elem);
	ft_putnbr(n, i, print);
	if (print)
		*i += ft_print_minchamps(elem);
}

int	ft_check_flags_putnbr(t_arg elem, int n, int print)
{
	int	i;

	i = 0;
	if (elem.f_minus == 0)
		ft_check_flags_putnbr2(&i, elem, n, print);
	else
		ft_check_flags_putnbr3(&i, elem, n, print);
	return (i);
}

void	ft_putnbr(int n, int *i, int print)
{
	if (n == -2147483648)
	{
		if (print)
			write(1, "2147483648", 10);
		*i += 10;
		return ;
	}
	if (n > 9 || n < -9)
		ft_putnbr(10, i, print);
	if (print)
		ft_putchar((char)((ft_abs(n % 10)) + 48), print);
	*i += 1;
}
