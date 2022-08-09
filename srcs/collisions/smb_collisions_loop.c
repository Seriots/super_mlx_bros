/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_loop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:45:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/09 18:50:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

int	boucle_col_down(t_collisions col, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < col.height)
	{
		j = -1;
		while (++j < col.width)
		{
			if (game->map.map_data[col.y + i][col.x + j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE,
					.height = TILES_SIZE, .x = (col.x + j) * TILES_SIZE,
					.y = (col.y + i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}

int	boucle_col_up(t_collisions col, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < col.height)
	{
		j = -1;
		while (++j < col.width)
		{
			if (game->map.map_data[col.y - i][col.x + j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE,
					.height = TILES_SIZE, .x = (col.x + j) * TILES_SIZE,
					.y = (col.y - i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}

int	boucle_col_right(t_collisions col, t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < col.width)
	{
		i = -1;
		while (++i < col.height)
		{
			if (game->map.map_data[col.y + i][col.x + j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE,
					.height = TILES_SIZE, .x = (col.x + j) * TILES_SIZE,
					.y = (col.y + i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}

int	boucle_col_left(t_collisions col, t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < col.width)
	{
		i = -1;
		while (++i < col.height)
		{
			if ((col.x - j) >= 0
				&& game->map.map_data[col.y + i][col.x - j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE,
					.height = TILES_SIZE, .x = (col.x - j) * TILES_SIZE,
					.y = (col.y + i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}
