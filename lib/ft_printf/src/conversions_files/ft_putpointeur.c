/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointeur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:46:23 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:56:11 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "conversions.h"
#include "ft_printf.h"

void	ft_check_flags_putpointeur2(int *i, void *ptr, int print, t_arg elem)
{
	if (print && ptr != 0 && elem.f_zero == 1)
		write(1, "0x", 2);
	if (print)
		*i += ft_print_minchamps(elem);
	if (print && ptr != 0 && elem.f_zero == 0)
		write(1, "0x", 2);
	if (print && ptr != 0)
		*i += ft_print_precision(elem);
	*i += ft_putpointeur(ptr, print);
}

void	ft_check_flags_putpointeur3(int *i, void *ptr, int print, t_arg elem)
{
	if (print && ptr != 0)
		write(1, "0x", 2);
	if (print && ptr != 0)
		*i += ft_print_precision(elem);
	*i += ft_putpointeur(ptr, print);
	if (print)
		*i += ft_print_minchamps(elem);
}

int	ft_check_flags_putpointeur(t_arg elem, void	*ptr, int print)
{
	int	i;

	i = 0;
	if (elem.f_plus == 1 && ptr != 0)
	{
		if (print)
			write (1, "+", 1);
		i = 1;
	}
	else if (elem.f_space == 1 && ptr != 0)
	{
		if (print)
			write (1, " ", 1);
		i = 1;
	}
	if (ptr == 0)
		elem.f_zero = 0;
	if (elem.f_minus == 0)
		ft_check_flags_putpointeur2(&i, ptr, print, elem);
	else
		ft_check_flags_putpointeur3(&i, ptr, print, elem);
	if (!print && ptr != 0)
		i -= 2;
	return (i);
}

void	ft_writepointeur(unsigned long addr, int *i, int print)
{
	if (addr > 15)
		ft_writepointeur(addr / 16, i, print);
	if (print)
		ft_putchar((char)(BASE_HEXA_MIN[addr % 16]), print);
	*i += 1;
}

int	ft_putpointeur(void	*p, int print)
{
	int				i;
	unsigned long	addr;

	i = 0;
	if (p == 0)
	{
		if (print == 1)
			write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)p;
	ft_writepointeur(addr, &i, print);
	return (i + 2);
}
