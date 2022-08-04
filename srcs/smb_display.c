/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:55:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 01:27:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"

#include "mlx.h"

#include <stdio.h>

unsigned int	get_pxl_color(t_img_data img, int x, int y)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	put_bg_to_image(t_game *game, int position, t_img_data *img)
{
	unsigned int	color;
	char			*dst;
	int				x;
	int				y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			dst = img->addr + (y * img->line_length
					+ x * (img->bits_per_pixel / 8));
			color = get_pxl_color(game->background,
					(x + position) % game->background.width, y);
			if (*(unsigned int *)dst != color)
				*(unsigned int *)dst = color;
			x++;
		}
		y ++;
	}
}

int	display(t_game *game)
{
	if (game->refresh)
	{
		put_bg_to_image(game, (int)game->x_position, &game->window_image);
		mlx_put_image_to_window(game->mlx.display,
			game->mlx.window, game->window_image.img, 0, 0);
		game->refresh = false;
	}
	return (0);
}
