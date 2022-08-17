/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:55:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:29:38 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

unsigned int	get_pxl_color(t_img_data img, int x, int y)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

t_coord	get_coord(int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

int	display_ingame(t_game *game)
{
	put_bg_to_image(game, (int)(game->x_position * BG_PARALLAX_FACTOR),
		&game->window_image);
	put_map_to_image(game, game->map.map_data, (int)game->x_position);
	put_objects_to_image(game, game->map.all_object,
		(int)game->x_position, &game->window_image);
	strdisplay(game, "Timer: %t", get_coord(10, 4), game->map.time);
	strdisplay(game, "Coins: %d", get_coord(200, 4), game->player.coins);
	strdisplay(game, "Final score: %d", get_coord(400, 4),
		game->player.final_score);
	put_player_to_image(game, &game->player, &game->window_image);
	mlx_put_image_to_window(game->mlx.display,
		game->mlx.window, game->window_image.img, 0, 0);
	return (0);
}
