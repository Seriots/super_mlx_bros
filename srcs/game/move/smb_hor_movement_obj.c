/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_hor_movement_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:23:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 13:31:35 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

int	apply_hor_movement_obj(t_game *game, t_object *obj)
{
	if (obj->x + obj->x_speed < 0 || obj->x + obj->x_speed > game->map.width - obj->width)
	{
		if (obj->x_speed > 0)
			obj->x = game->map.width - obj->width;
		else
			obj->x = 0;
		obj->x_speed = -obj->x_speed;
	}
	if (check_collisions_obj(game, obj, obj->x + obj->x_speed, obj->y))
	{
		if (obj->x_speed > 0)
			obj->x = obj->col_object.x - obj->width;
		else
			obj->x = obj->col_object.x + obj->col_object.width;
		obj->x_speed = -obj->x_speed;
	}
	else
		obj->x += obj->x_speed;
	return (0);
}
