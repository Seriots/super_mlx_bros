/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_fireball.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:17:28 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 15:53:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"
#include "smb_settings.h"
#include "smb.h"

#include <stdlib.h>

int	fireball_player_update_speed(t_object *obj)
{
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
	if (obj->y_acceleration > FB_MAX_SPEED)
		obj->y_acceleration = FB_MAX_SPEED;
	else if (obj->y_acceleration < -FB_MAX_SPEED)
		obj->y_acceleration = -FB_MAX_SPEED;
	return (0);
}

int	fireball_player_update_y(t_game *game, t_object *obj)
{
	int	ret_val;

	fireball_player_update_speed(obj);
	ret_val = check_collisions_fireball(game, obj, obj->x,
			obj->y + obj->y_speed);
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
	int	ret_val;

	ret_val = check_collisions_fireball(game, obj,
			obj->x + obj->x_speed, obj->y);
	if (!ret_val)
		obj->x += obj->x_speed;
	else if (ret_val == 2)
		return (1);
	else
	{
		if ((obj->col_object.direction == RIGHT
				&& obj->col_object.x == obj->x - obj->width)
			|| (obj->col_object.direction == LEFT
				&& obj->col_object.x == obj->x + obj->col_object.width))
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
	int	ret_val;

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

	(void)elem;
	update_obj_img(game, obj, 0);
	i = 0;
	retval = 0;
	while (i < game->delay && retval == 0)
	{
		retval = fireball_player_update_movement(game, obj);
		if (retval == 1)
			obj->update_fonction = obj->del_fonction;
		i++;
	}
	return (0);
}
