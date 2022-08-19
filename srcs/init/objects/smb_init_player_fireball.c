/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_player_fireball.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:33:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 11:30:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb_settings.h"
#include "smb.h"

#include <stdlib.h>
#include <math.h>

#include <stdio.h>

int	fireball_player_update_y(t_game *game, t_object *obj)
{
	int	ret_val;

	obj->y_acceleration += FB_GRAVITY;
	if (obj->y_speed < 0 && obj->y_speed + obj->y_acceleration > 0)
	{
		obj->y_speed += obj->y_acceleration;
		obj->y_acceleration = 0;
	}
	else
		obj->y_speed += obj->y_acceleration;
	if (obj->y_speed > FB_MAX_SPEED)
		obj->y_speed = FB_MAX_SPEED;
	else if (obj->y_speed < -FB_MAX_SPEED)
		obj->y_speed = -FB_MAX_SPEED;
	ret_val = check_collisions_fireball(game , obj, obj->x, obj->y + obj->y_speed);
	if (!ret_val)
		obj->y += obj->y_speed;
	else if (ret_val == 2)
		return (1);
	else
	{
		if (obj->col_object.direction == DOWN)
		{
			obj->y = obj->col_object.y - obj->height;
			obj->y_speed = -FB_UP_SPEED;
			obj->y_acceleration = 0;
		}
		else
			return (1);
	}
	return (0);
}

int	fireball_player_update_x(t_game *game, t_object *obj)
{
	int ret_val;

	ret_val = check_collisions_fireball(game , obj, obj->x + obj->x_speed, obj->y);
	if (!ret_val)
		obj->x += obj->x_speed;
	else if (ret_val == 2)
		return (1);
	else
	{
		if ((obj->col_object.direction == RIGHT && obj->col_object.x == obj->x - obj->width)
			|| (obj->col_object.direction == LEFT && obj->col_object.x == obj->x + obj->col_object.width))
			return (1);
		else
		{
			if (obj->col_object.direction == RIGHT)
				obj->x = obj->col_object.x - obj->width;
			else
				obj->x = obj->col_object.x + obj->col_object.width;
		}
		return (1);
	}
	return (0);
}

int	fireball_player_update_movement(t_game *game, t_object *obj)
{
	int ret_val;

	if (obj->start_frame + FB_LIVE_DURATION < game->current_frame)
		return (1);
	ret_val = fireball_player_update_y(game, obj);
	if (ret_val)
		return (ret_val);
	ret_val = fireball_player_update_x(game, obj);
	if (ret_val)
		return (ret_val);
	return (0);
}

int	fireball_player_update(t_game *game, t_dict *elem, t_object *obj)
{
	int	i;
	int	retval;

	update_obj_img(game, obj);
	i = 0;
	retval = 0;
	while (i < game->delay && retval == 0)
	{
		retval = fireball_player_update_movement(game, obj);
		if (retval == 1)
			dict_delone(&game->map.all_object, elem, 0, free);
		i++;
	}
	return (0);
}

void	init_fireball_player(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_fireballs;
	(*obj)->img = &game->all_images.all_fireballs[0];
	(*obj)->animation_duration = FB_ANIM_DURATION;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 0;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 4;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = 0;
	(*obj)->update_fonction = fireball_player_update;
	if (game->player.orientation == O_RIGHT)
		(*obj)->x_speed = FB_SPEED_PLAYER;
	else
		(*obj)->x_speed = -FB_SPEED_PLAYER;
	(*obj)->y_speed = -FB_START_UP_SPEED;
	(*obj)->y_acceleration = 0.0;
}