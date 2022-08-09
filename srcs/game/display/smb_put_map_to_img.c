/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_put_map_to_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:50:49 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 00:52:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

static t_img_data	get_tile_next(t_game *game, char c)
{
	/*static struct {char c, int i} = {
		{'I', 2}*/
	if (c == 'I')
		return (game->all_images.all_tiles[2]);
	if (c == 'E')
		return (game->all_images.all_tiles[7]);
	if (c == 'F')
		return (game->all_images.all_tiles[8]);
	if (c == 'B')
		return (game->all_images.all_tiles[6]);
	if (c == 'A')
		return (game->all_images.all_tiles[1]);
	if (c == 'C')
		return (game->all_images.all_tiles[9]);
	if (c == 'D')
		return (game->all_images.all_tiles[13]);
	if (c == 'G')
		return (game->all_images.all_tiles[14]);
	if (c == 'H')
		return (game->all_images.all_tiles[15]);
	return (game->all_images.all_tiles[0]);
}

static t_img_data	get_tile(t_game *game, char c)
{
	if (c == 'P')
		return (game->all_images.all_tiles[0]);
	if (c == 'N')
		return (game->all_images.all_tiles[4]);
	if (c == 'O')
		return (game->all_images.all_tiles[12]);
	if (c == 'L')
		return (game->all_images.all_tiles[11]);
	if (c == 'M')
		return (game->all_images.all_tiles[5]);
	if (c == 'J')
		return (game->all_images.all_tiles[3]);
	if (c == 'K')
		return (game->all_images.all_tiles[10]);
	return (get_tile_next(game, c));
}

static void	put_tile(t_game *game, int x, int y, int position)
{
	unsigned int	color;
	char			*dst;
	int				x_tile;
	int				y_tile;

	y_tile = -1;
	while (++y_tile < TILES_SIZE)
	{
		x_tile = -1;
		while (++x_tile < TILES_SIZE)
		{
			if (x * TILES_SIZE + x_tile - position >= 0
				&& x * TILES_SIZE + x_tile - position < SCREEN_WIDTH)
			{
				dst = game->window_image.addr + ((y * TILES_SIZE + y_tile)
						* game->window_image.line_length
						+ (x * TILES_SIZE + x_tile - position)
						* (game->window_image.bits_per_pixel / 8));
				color = get_pxl_color(get_tile(game, game->map.map_data[y][x]),
						x_tile, y_tile);
				if (*(unsigned int *)dst != color && color != 4278190080)
					*(unsigned int *)dst = color;
			}
		}
	}
}

void	put_map_to_image(t_game *game, char **map, int position)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAP_HEIGHT_TILES)
	{
		x = floor(position / TILES_SIZE);
		while (x < MAP_WIDTH_TILES + floor(position / TILES_SIZE) + 1)
		{
			if (map[y][x] != '0')
				put_tile(game, x, y, position);
			x++;
		}
		y ++;
	}
}
