/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_gravity_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:07:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 09:20:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

int	apply_gravity_obj(t_game *game, t_object *obj)
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
		{
			obj->y_acceleration += GRAVITY_DOWN;
			obj->y_speed += obj->y_acceleration;
			if (obj->y_speed > GBA_Y_MAX_SPEED)
				obj->y_speed = GBA_Y_MAX_SPEED;
			if (obj->y_acceleration > GBA_Y_MAX_SPEED)
				obj->y_acceleration = GBA_Y_MAX_SPEED;
			if (check_collisions_obj(game, obj, obj->x, obj->y + obj->y_speed))
			{
				obj->y_speed = 0;
				obj->y_acceleration = 0;
				obj->y = obj->col_object.y - obj->height;
			}
			else
				obj->y += obj->y_speed;
		}
		i++;
	}
	return (0);
}