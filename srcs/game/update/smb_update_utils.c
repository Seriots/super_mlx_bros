/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:14:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 03:28:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"

#include <math.h>

int	is_in_map(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map.width / TILES_SIZE
		|| y < 0 || y >= game->map.height / TILES_SIZE)
		return (0);
	return (1);
}

int	i_can_move(t_game *game, t_player *player)
{
	int	y;
	int	x;
	int	y_height;
	int	x_width;

	y = (int)floor(player->y_pos) / TILES_SIZE;
	x = (int)floor(player->x_pos + game->x_position) / TILES_SIZE;
	y_height = (int)floor(player->y_pos + player->height) / TILES_SIZE;
	x_width = (int)floor(player->x_pos + game->x_position + player->width)
		/ TILES_SIZE;
	if ((int)floor(player->x_pos + game->x_position + player->width)
		% TILES_SIZE == 0)
		x_width -= 1;
	if ((int)floor(player->y_pos + player->height) % TILES_SIZE == 0)
		y_height -= 1;
	if (is_in_map(game, x, y) && game->map.map_data[y][x] != '0')
		return (0);
	if (is_in_map(game, x_width, y) && game->map.map_data[y][x_width] != '0')
		return (0);
	if (is_in_map(game, x, y_height) && game->map.map_data[y_height][x] != '0')
		return (0);
	if (is_in_map(game, x_width, y_height)
		&& game->map.map_data[y_height][x_width] != '0')
		return (0);
	return (1);
}
