/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_gravity_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:07:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:34:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

static int	obj_fall(t_game *game, t_object *obj, float max_speed)
{
	(void)game;
	obj->y_acceleration += GRAVITY_DOWN;
	obj->y_speed += obj->y_acceleration;
	if (obj->y_speed > max_speed)
		obj->y_speed = max_speed;
	if (obj->y_acceleration > max_speed)
		obj->y_acceleration = max_speed;
	if (check_collisions_obj(game, obj, obj->x, obj->y + obj->y_speed))
	{
		obj->y_speed = 0;
		obj->y_acceleration = 0;
		obj->y = obj->col_object.y - obj->height;
	}
	else
		obj->y += obj->y_speed;
	return (0);
}

int	apply_gravity_obj(t_game *game, t_object *obj, float max_speed)
{
	int	i;

	i = 0;
	while (i < game->delay)
	{
		if (check_collisions_bottom_obj(game, obj, obj->x, obj->y))
		{
			obj->y_speed = 0;
			obj->y_acceleration = 0;
		}
		else
			obj_fall(game, obj, max_speed);
		i++;
	}
	return (0);
}
