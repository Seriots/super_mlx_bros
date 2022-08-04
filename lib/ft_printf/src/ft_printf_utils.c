/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:45:00 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:20 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i ++;
	}
	return (-1);
}

void	ft_setzero(int flags[5])
{
	int	i;

	i = -1;
	while (++i < 5)
		flags[i] = 0;
}

t_arg	ft_convert_flags(int flags[5], t_arg elem)
{
	elem.f_zero = flags[0];
	elem.f_space = flags[1];
	elem.f_plus = flags[2];
	elem.f_minus = flags[3];
	elem.f_hashtag = flags[4];
	return (elem);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_init(t_arg *elem)
{
	elem->f_zero = 0;
	elem->f_space = 0;
	elem->f_plus = 0;
	elem->f_minus = 0;
	elem->f_hashtag = 0;
	elem->min_champs = 0;
	elem->precision = 0;
	elem->precision_detected = 0;
	elem->attribut = 0;
}
