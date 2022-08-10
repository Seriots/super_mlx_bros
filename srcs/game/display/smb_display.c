/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:55:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/10 20:35:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdio.h>

unsigned int	get_pxl_color(t_img_data img, int x, int y)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	display(t_game *game)
{
	put_bg_to_image(game, (int)(game->x_position * BG_PARALLAX_FACTOR),
		&game->window_image);
	put_map_to_image(game, game->map.map_data, (int)game->x_position);
	put_objects_to_image(game, game->map.all_object, (int)game->x_position, &game->window_image);
	put_player_to_image(game, &game->player, &game->window_image);
	mlx_put_image_to_window(game->mlx.display,
		game->mlx.window, game->window_image.img, 0, 0);
	return (0);
}