/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:45:49 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:19 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversions.h"
#include "ft_printf.h"

int	ft_check_puthexa_min(t_arg elem, unsigned int n)
{
	int	i;
	int	hashmark;

	hashmark = 0;
	if (n == 0 && elem.precision_detected == 1 && elem.precision == 0)
	{
		elem.min_champs -= elem.precision;
		i = ft_print_minchamps(elem);
		i += ft_print_precision(elem);
		return (i);
	}
	if (n != 0 && elem.f_hashtag == 1)
		hashmark = 2;
	i = ft_check_flags_puthexa_min(elem, n, 0);
	elem.precision -= i;
	if (elem.precision > 0)
		elem.min_champs -= i + elem.precision + hashmark;
	else
		elem.min_champs -= i + hashmark;
	return (ft_check_flags_puthexa_min(elem, n, 1));
}

void	ft_check_puthexa_min2(int *i, t_arg elem, unsigned int n, int print)
{
	if (elem.f_hashtag == 1 && n != 0 && elem.f_zero == 1)
	{
		if (print)
			write(1, "0x", 2);
		if (print)
			*i += 2;
	}
	if (print)
		*i += ft_print_minchamps(elem);
	if (elem.f_hashtag == 1 && n != 0 && elem.f_zero == 0)
	{
		if (print)
			write(1, "0x", 2);
		if (print)
			*i += 2;
	}
	if (print)
		*i += ft_print_precision(elem);
	ft_puthexa_min(n, i, print);
}

int	ft_check_flags_puthexa_min(t_arg elem, unsigned int n, int print)
{
	int	i;

	i = 0;
	if (elem.f_minus == 0)
		ft_check_puthexa_min2(&i, elem, n, print);
	else
	{
		if (elem.f_hashtag == 1 && n != 0)
		{
			if (print)
				write(1, "0x", 2);
			if (print)
				i += 2;
		}
		if (print)
			i += ft_print_precision(elem);
		ft_puthexa_min(n, &i, print);
		if (print)
			i += ft_print_minchamps(elem);
	}
	return (i);
}

void	ft_puthexa_min(unsigned int n, int *i, int print)
{
	if (n > 15)
		ft_puthexa_min(16, i, print);
	if (print)
		ft_putchar((char)(BASE_HEXA_MIN[n % 16]), print);
	*i += 1;
}
