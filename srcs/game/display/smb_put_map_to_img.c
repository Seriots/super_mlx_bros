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

#include <stdio.h>

static t_img_data	get_tile(t_game *game, char c)
{
	int			i;
	static char	set[] = {'P', 'A', 'I', 'J', 'N', 'M', 'B', 'E',
		'F', 'C', 'K', 'L', 'O', 'D', 'G', 'H'};

	i = 0;
	while (i < 16)
	{
		if (set[i] == c)
			return (game->all_images.all_tiles[i]);
		i++;
	}
	return (game->all_images.all_tiles[0]);
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
