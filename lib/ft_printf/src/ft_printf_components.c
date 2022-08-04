/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_components.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:44:28 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/07/12 15:32:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "conversions.h"
#include "ft_printf.h"
#include "libft.h"

t_arg	ft_check_precision(const char *s, int *i, t_arg elem)
{
	elem.precision_detected = 0;
	if (s[*i] == '.' && ft_isdigit(s[*i + 1]))
	{
		elem.precision = 0;
		elem.precision_detected = 1;
		while (ft_isdigit(s[++(*i)]))
			elem.precision = (elem.precision * 10) + (s[*i] - 48);
	}
	else if (s[*i] == '.')
	{
		*i += 1;
		elem.precision_detected = 1;
	}
	return (elem);
}

t_arg	ft_parse(const char *s, int *position)
{
	int		i;
	int		flags[5];
	t_arg	elem;

	i = *position;
	ft_setzero(flags);
	ft_init(&elem);
	while (ft_is_base(s[++i], FLAG_BASE) != -1 && s[i])
		flags[ft_is_base(s[i], FLAG_BASE)] = 1;
	elem = ft_convert_flags(flags, elem);
	i -= 1;
	while (ft_isdigit(s[++i]))
		elem.min_champs = (elem.min_champs * 10) + (s[i] - 48);
	elem = ft_check_precision(s, &i, elem);
	if (ft_is_base(s[i], ATTRIBUT_BASE) != -1)
		elem.attribut = s[i++];
	else
		elem.attribut = 0;
	*position = i - 1;
	return (elem);
}

int	ft_printf_args(t_arg el, va_list ap)
{
	int	i;

	i = 0;
	if (el.attribut == 'd' || el.attribut == 'i')
		i = ft_check_putnbr(el, va_arg(ap, int));
	else if (el.attribut == 'c')
		i = ft_check_putchar(el, (char)va_arg(ap, int));
	else if (el.attribut == 's')
		i = ft_check_putstr(el, va_arg(ap, char *));
	else if (el.attribut == 'p')
		i = ft_check_putpointeur(el, (void *)va_arg(ap, void *));
	else if (el.attribut == 'u')
		i = ft_check_putnbrunsigned(el, (unsigned int)va_arg(ap, unsigned int));
	else if (el.attribut == 'x')
		i = ft_check_puthexa_min(el, (unsigned int)va_arg(ap, unsigned int));
	else if (el.attribut == 'X')
		i = ft_check_puthexa_maj(el, (unsigned int)va_arg(ap, unsigned int));
	else if (el.attribut == '%')
	{
		write(1, "%", 1);
		i = 1;
	}
	return (i);
}

int	ft_check_parse(t_arg element, va_list ap, int *i, const char *s)
{
	int	tmp;
	int	count;

	count = 0;
	tmp = *i;
	element = ft_parse(s, i);
	if (element.attribut == 0)
	{
		write(1, "%", 1);
		*i = tmp;
		count ++;
	}
	else
		count += ft_printf_args(element, ap);
	return (count);
}

int	ft_printfwork(va_list ap, const char *s)
{
	int		i;
	int		count;
	t_arg	element;

	i = 0;
	ft_init(&element);
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
			count += ft_check_parse(element, ap, &i, s);
		else
		{
			write(1, &s[i], 1);
			count ++;
		}
		if (s[i])
			i ++;
	}
	return (count);
}
