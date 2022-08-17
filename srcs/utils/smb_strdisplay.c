/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_strdisplay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:18:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:23:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "mlx.h"
#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdarg.h>

#include <stdio.h>

int	print_proceed(t_game *game, const char *str, va_list lst, t_coord coord)
{
	int	i;
	int	char_count;

	i = 0;
	char_count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			char_count += char_put(game, str[i], &coord);
		else
			char_count += convert_put(game, str[++i], lst, &coord);
		i++;
	}
	return (char_count);
}

int	strdisplay(t_game *game, const char *str, t_coord coord, ...)
{
	va_list	lst;
	int		size;

	if (!str)
		return (0);
	va_start(lst, coord);
	size = print_proceed(game, str, lst, coord);
	va_end(lst);
	return (size);
}
