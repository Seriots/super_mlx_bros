/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_put_player_to_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:03:25 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 20:56:58 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

void	put_player_to_image(t_game *game, t_player *player, t_img_data *img)
{
	unsigned int	color;
	char			*dst;
	int				x;
	int				y;

	(void)game;
	y = 0;
	while (y < player->height)
	{
		x = 0;
		while (x < player->width)
		{
			if (player->x_pos + x >= 0 && player->x_pos + x <= SCREEN_WIDTH
				&& player->y_pos + y <= SCREEN_HEIGHT && player->y_pos + y >= 0)
			{
				dst = img->addr + ((int)(y + player->y_pos) * img->line_length
						+ (int)(x + player->x_pos) * (img->bits_per_pixel / 8));
				color = get_pxl_color(player->img_player, x, y);
				if (*(unsigned int *)dst != color && color != 4278190080)
					*(unsigned int *)dst = color;
			}
			x++;
		}
		y ++;
	}
}
