/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:44:21 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:20 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;

	if (!s)
		return (0);
	va_start(ap, s);
	i = ft_printfwork(ap, s);
	va_end(ap);
	return (i);
}
