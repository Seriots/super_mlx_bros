/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_obj_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:45:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:45:32 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

int	check_col_left_obj(t_game *game, t_object *obj, float x_pos)
{
	t_collisions	col;

	col.x = (int)ceil(obj->x);
	col.y = (int)floor(obj->y);
	col.height = ((col.y + obj->height - 1) / TILES_SIZE)
		- (col.y / TILES_SIZE) + 1;
	col.width = (((col.x) / TILES_SIZE)
			- (int)floor(x_pos) / TILES_SIZE) + 1;
	col.x = col.x / TILES_SIZE;
	col.y /= TILES_SIZE;
	col.direction = LEFT;
	return (boucle_col_left_obj(col, game, obj));
}

int	check_col_right_obj(t_game *game, t_object *obj, float x_pos)
{
	t_collisions	col;

	col.x = (int)floor(obj->x);
	col.y = (int)floor(obj->y);
	col.height = ((col.y + obj->height - 1) / TILES_SIZE)
		- (col.y / TILES_SIZE) + 1;
	col.width = (((int)ceil(x_pos + obj->width) / TILES_SIZE
				- col.x / TILES_SIZE)) + 1;
	col.x /= TILES_SIZE;
	col.y /= TILES_SIZE;
	col.direction = RIGHT;
	return (boucle_col_right_obj(col, game, obj));
}

int	check_col_up_obj(t_game *game, t_object *obj, float y_pos)
{
	t_collisions	col;

	col.x = (int)floor(obj->x);
	col.y = (int)ceil(obj->y);
	col.height = (((col.y) / TILES_SIZE)
			- ((int)floor(y_pos) / TILES_SIZE)) + 1;
	col.width = ((col.x + obj->width - 1) / TILES_SIZE)
		- (col.x / TILES_SIZE) + 1;
	col.x /= TILES_SIZE;
	col.y = col.y / TILES_SIZE;
	col.direction = UP;
	return (boucle_col_up_obj(col, game, obj));
}

int	check_col_down_obj(t_game *game, t_object *obj, float y_pos)
{
	t_collisions	col;

	col.x = (int)floor(obj->x);
	col.y = (int)floor(obj->y);
	col.height = (((int)ceil(y_pos) + obj->height)
			/ TILES_SIZE - (col.y) / TILES_SIZE) + 1;
	col.width = ((col.x + obj->width - 1)
			/ TILES_SIZE) - (col.x / TILES_SIZE) + 1;
	col.x /= TILES_SIZE;
	col.y = (col.y) / TILES_SIZE;
	col.direction = DOWN;
	return (boucle_col_down_obj(col, game, obj));
}

int	check_col_obj_map(t_game *game, t_object *obj, float x_pos, float y_pos)
{
	if (obj->x > x_pos)
		return (check_col_left_obj(game, obj, x_pos));
	else if (obj->x < x_pos)
		return (check_col_right_obj(game, obj, x_pos));
	else if (obj->y > y_pos)
		return (check_col_up_obj(game, obj, y_pos));
	else if (obj->y < y_pos)
		return (check_col_down_obj(game, obj, y_pos));
	else
		return (0);
}
