/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointeur2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 00:46:33 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/06/09 00:51:19 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "ft_printf.h"

int	ft_check_putpointeur(t_arg elem, void *ptr)
{
	int	i;

	i = ft_check_flags_putpointeur(elem, ptr, 0);
	elem.precision -= i;
	if (elem.precision > 0)
	{	
		if (ptr != 0)
			elem.min_champs -= i + elem.precision + 2;
		else
			elem.min_champs -= i + elem.precision;
	}
	else
	{
		if (ptr != 0)
			elem.min_champs -= i + 2;
		else
			elem.min_champs -= i;
	}
	return (ft_check_flags_putpointeur(elem, ptr, 1));
}
