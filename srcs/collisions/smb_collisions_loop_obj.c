/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_loop_obj.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:41:53 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:43:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

int	boucle_col_down_obj(t_collisions col, t_game *game, t_object *obj)
{
	int	i;
	int	j;

	i = -1;
	while (++i < col.height)
	{
		j = -1;
		while (++j < col.width)
		{
			if (col.x + j >= 0 && col.x + j < game->map.width / TILES_SIZE
				&& col.y + i >= 0 && col.y + i < game->map.height / TILES_SIZE)
			{
				if (game->map.map_data[col.y + i][col.x + j] != '0')
				{
					obj->col_object = (t_collisions){.width = TILES_SIZE,
						.height = TILES_SIZE, .x = (col.x + j) * TILES_SIZE,
						.y = (col.y + i) * TILES_SIZE,
						.direction = col.direction};
					return (1);
				}
			}
		}
	}
	return (0);
}

int	boucle_col_up_obj(t_collisions col, t_game *game, t_object *obj)
{
	int	i;
	int	j;

	i = -1;
	while (++i < col.height)
	{
		j = -1;
		while (++j < col.width)
		{
			if (col.x + j >= 0 && col.x + j < game->map.width / TILES_SIZE
				&& col.y - i >= 0 && col.y - i < game->map.height / TILES_SIZE)
			{
				if (game->map.map_data[col.y - i][col.x + j] != '0')
				{
					obj->col_object = (t_collisions){.width = TILES_SIZE,
						.height = TILES_SIZE, .x = (col.x + j) * TILES_SIZE,
						.y = (col.y - i) * TILES_SIZE,
						.direction = col.direction};
					return (1);
				}
			}
		}
	}
	return (0);
}

int	boucle_col_right_obj(t_collisions col, t_game *game, t_object *obj)
{
	int	i;
	int	j;

	j = -1;
	while (++j < col.width)
	{
		i = -1;
		while (++i < col.height)
		{
			if (col.x + j >= 0 && col.x + j < game->map.width / TILES_SIZE
				&& col.y + i >= 0 && col.y + i < game->map.height / TILES_SIZE)
			{
				if (game->map.map_data[col.y + i][col.x + j] != '0')
				{
					obj->col_object = (t_collisions){.width = TILES_SIZE,
						.height = TILES_SIZE, .x = (col.x + j) * TILES_SIZE,
						.y = (col.y + i) * TILES_SIZE,
						.direction = col.direction};
					return (1);
				}
			}
		}
	}
	return (0);
}

int	boucle_col_left_obj(t_collisions col, t_game *game, t_object *obj)
{
	int	i;
	int	j;

	j = -1;
	while (++j < col.width)
	{
		i = -1;
		while (++i < col.height)
		{
			if (col.x - j >= 0 && col.x - j < game->map.width / TILES_SIZE
				&& col.y + i >= 0 && col.y + i < game->map.height / TILES_SIZE)
			{
				if (game->map.map_data[col.y + i][col.x - j] != '0')
				{
					obj->col_object = (t_collisions){.width = TILES_SIZE,
						.height = TILES_SIZE, .x = (col.x - j) * TILES_SIZE,
						.y = (col.y + i) * TILES_SIZE,
						.direction = col.direction};
					return (1);
				}
			}
		}
	}
	return (0);
}
