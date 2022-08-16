/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_strdisplay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 03:18:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/16 18:31:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "mlx.h"
#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdarg.h>

#include <stdio.h>

int	char_put(t_game *game, char c, t_coord *coord)
{
	int	value;
	
	if (c < 32 || c > 32 + CHAR_NUMBER - 1)
		value = 0;
	else
		value = (c - 32);
	put_char_to_img(game, coord->x, coord->y, &game->all_images.all_characters[value].img);
	coord->x += game->all_images.all_characters[value].width;
	return (0);
}

int	string_put(t_game *game, char *str, t_coord *coord)
{
	int i;

	i = 0;
	while (str[i])
		i += char_put(game, str[i], coord);
	return (i);
}

int	int_put(t_game *game, int nb, t_coord *coord)
{
	if (nb == -2147483648)
		return (string_put(game, "-2147483648", coord));
	else if (nb < 0)
	{
		nb = -nb;
		char_put(game, '-', coord);
	}
	else if (nb > 9)
		return (int_put(game, nb / 10, coord) + char_put(game, nb % 10 + '0', coord));
	return (char_put(game, nb + '0', coord));
}

int time_put(t_game *game, long time, t_coord *coord)
{
	int i;

	i = 0;
	if (time >= 6000)
		time = 5999;
	i += char_put(game, '0' + time / 10 / 6 / 10, coord);
	i += char_put(game, '0' + time / 10 / 6 % 10, coord);
	i += char_put(game, ':', coord);
	i += char_put(game, '0' + time / 10 % 6, coord);
	i += char_put(game, '0' + time % 10, coord);
	return (i);
}

int	convert_put(t_game *game, char c, va_list lst, t_coord *coord)
{
	if (c == 'd' || c == 'i')
		return (int_put(game, va_arg(lst, int), coord));
	else if (c == 's')
		return (string_put(game, va_arg(lst, char *), coord));
	else if (c == 't')
		return (time_put(game, va_arg(lst, long), coord));
	else
		return (char_put(game, c, coord));
}

int	print_proceed(t_game *game, const char *str, va_list lst, t_coord coord)
{
	int	i;
	int char_count;

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