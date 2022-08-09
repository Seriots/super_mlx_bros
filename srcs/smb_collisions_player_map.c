/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_player_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:21:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/09 17:30:48 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

#include <stdio.h>
/*
* Return 1: Collide
* Return 0: No-Collide
*/

static int	check_col_left(t_game *game, float x_pos, float pos)
{
	t_collisions	col;
	int	i;
	int	j;
	
	col.x = (int)ceil(game->player.x_pos + game->x_position);
	col.y = (int)floor(game->player.y_pos);
	col.height = ((col.y + game->player.height - 1) / TILES_SIZE) - (col.y / TILES_SIZE) + 1;
	col.width = (((col.x) / TILES_SIZE) - (int)floor(x_pos + pos) / TILES_SIZE) + 1;
	//printf("LEFT>w: %d, h: %d\n", col.width, col.height);
	col.x = col.x / TILES_SIZE;
	col.y /= TILES_SIZE;
	j = -1;
	while (++j < col.width)
	{
		i = -1;
		while (++i < col.height)
		{
			if ((col.x - j) >= 0 && game->map.map_data[col.y + i][col.x - j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE, .height = TILES_SIZE,
						.x = (col.x - j) * TILES_SIZE, .y = (col.y + i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}

static int	check_col_right(t_game *game, float x_pos, float pos)
{
	t_collisions	col;
	int	i;
	int	j;
	
	col.x = (int)floor(game->player.x_pos + game->x_position);
	col.y = (int)floor(game->player.y_pos);
	col.height = ((col.y + game->player.height - 1) / TILES_SIZE) - (col.y / TILES_SIZE) + 1;
	col.width = (((int)ceil(x_pos + pos + game->player.width) / TILES_SIZE - col.x / TILES_SIZE)) + 1;
	//printf("RIGHT>w: %d, h: %d\n", col.width, col.height);
	col.x /= TILES_SIZE;
	col.y /= TILES_SIZE;
	j = -1;
	while (++j < col.width)
	{
		i = -1;
		while (++i < col.height)
		{
			if (game->map.map_data[col.y + i][col.x + j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE, .height = TILES_SIZE,
						.x = (col.x + j) * TILES_SIZE, .y = (col.y + i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}

static int	check_col_up(t_game *game, float y_pos)
{
	t_collisions	col;
	int	i;
	int	j;
	
	col.x = (int)floor(game->player.x_pos + game->x_position);
	col.y = (int)ceil(game->player.y_pos);
	col.height = (((col.y) / TILES_SIZE) - ((int)floor(y_pos)  / TILES_SIZE)) + 1;
	col.width = ((col.x + game->player.width - 1) / TILES_SIZE) - (col.x / TILES_SIZE) + 1;
	col.x /= TILES_SIZE;
	col.y = col.y / TILES_SIZE;
	i = -1;
	while (++i < col.height)
	{
		j = -1;
		while (++j < col.width)
		{
			if (game->map.map_data[col.y - i][col.x + j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE, .height = TILES_SIZE,
						.x = (col.x + j) * TILES_SIZE, .y = (col.y - i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}

static int	check_col_down(t_game *game, float y_pos)
{
	t_collisions	col;
	int	i;
	int	j;
	
	col.x = (int)floor(game->player.x_pos) + (int)floor(game->x_position);
	col.y = (int)floor(game->player.y_pos);
	col.height = (((int)ceil(y_pos)  + game->player.height) / TILES_SIZE - (col.y) / TILES_SIZE) + 1 ;
	col.width = ((col.x + game->player.width - 1) / TILES_SIZE) - (col.x / TILES_SIZE) + 1;
	col.x /= TILES_SIZE;
	col.y = (col.y) / TILES_SIZE;
	i = -1;
	while (++i < col.height)
	{
		j = -1;
		while (++j < col.width)
		{
			if (game->map.map_data[col.y + i][col.x + j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE, .height = TILES_SIZE,
						.x = (col.x + j) * TILES_SIZE, .y = (col.y + i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}

int	check_col_player_map(t_game *game, float x_pos, float y_pos, float pos) 
{
	//printf(">%f %f\n", game->x_position, game->player.x_pos);
	if (game->player.x_pos > x_pos || game->x_position > pos)
		return (check_col_left(game, x_pos, pos));
	else if (game->player.x_pos < x_pos  || game->x_position < pos)
		return (check_col_right(game, x_pos, pos));
	else if (game->player.y_pos > y_pos)
		return (check_col_up(game, y_pos));
	else if (game->player.y_pos < y_pos)
		return (check_col_down(game, y_pos));
	else
		return (0);		
}

/*
int	check_col_player_map(t_game *game, float x_pos, float y_pos, float pos)
{
	t_collisions	col;
	int				i;
	int				j;

	col.x = (int)floor(x_pos) + (int)floor(pos);
	col.y = (int)floor(y_pos);
	col.width = ((col.x + game->player.width - 1) / TILES_SIZE) - (col.x / TILES_SIZE) + 1;
	col.height = ((col.y + game->player.height - 1) / TILES_SIZE) - (col.y / TILES_SIZE) + 1;
	col.x /= TILES_SIZE;
	col.y /= TILES_SIZE;
	i = -1;
	while (++i < col.height)
	{
		j = -1;
		while (++j < col.width)
		{
			if (game->map.map_data[col.y + i][col.x + j] != '0')
			{
				game->collide_obj = (t_collisions){.width = TILES_SIZE, .height = TILES_SIZE,
						.x = (col.x + j) * TILES_SIZE, .y = (col.y + i) * TILES_SIZE};
				return (1);
			}
		}
	}
	return (0);
}*/
