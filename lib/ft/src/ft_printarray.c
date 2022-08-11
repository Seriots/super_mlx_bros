/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:41:46 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 20:10:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_printarray(char **array, int is_n)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_putstr_fd(array[i], 1);
		if (!is_n)
			ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
