/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_death_plant_piranha.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:01:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/22 12:57:28 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

int	update_piranha_death_pos(t_game *game, t_object *obj)
{
	int	i;

	i = 0;
	while (i < game->delay)
	{
		obj->x += obj->x_speed;
		obj->y_acceleration += PP_GRAVITY;
		obj->y_speed += obj->y_acceleration;
		if (obj->y_speed > PP_Y_MAX_SPEED)
			obj->y_speed = PP_Y_MAX_SPEED;
		obj->y += obj->y_speed;
		i++;
	}
	return (0);
}

int	init_piranha_death(t_game *game, t_object *obj)
{
	generate_wincoin(game, obj);
	init_point_image(game, obj, 1, 200);
	obj->animation_duration = PP_ANIM_DEATH_DURATION;
	obj->start_frame = game->current_frame;
	obj->nb_image = 8;
	obj->is_collide = 0;
	if (game->player.x_pos + game->x_position < obj->x)
		obj->x_speed = PP_X_DEATH_SPEED;
	else
		obj->x_speed = -PP_X_DEATH_SPEED;
	obj->y_speed = -PP_Y_DEATH_SPEED;
	obj->col_count ++;
	return (0);
}
