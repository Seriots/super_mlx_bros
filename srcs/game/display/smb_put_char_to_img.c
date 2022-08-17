/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_put_char_to_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:55:27 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:31:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

#include "mlx.h"

#include <stdio.h>

void	put_char_to_img(t_game *game, int x_start, int y_start, t_img_data *img)
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
			if (x_start + x >= 0 && x_start + x <= SCREEN_WIDTH
				&& y_start + y >= 0 && y_start + y <= SCREEN_HEIGHT)
			{
				dst = game->window_image.addr + (((int)(y + y_start))
						* game->window_image.line_length + ((int)(x + x_start))
						* (game->window_image.bits_per_pixel / 8));
				color = get_pxl_color(*img, x, y);
				if (*(unsigned int *)dst != color && color != 4278190080)
					*(unsigned int *)dst = color;
			}
			x++;
		}
		y ++;
	}
}
