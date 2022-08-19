/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_player_fireball.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 09:33:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 15:00:56 by lgiband          ###   ########.fr       */
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

int	fireball_player_del(t_game *game, t_dict *elem, t_object *obj)
{
	dict_delone(&game->map.all_object, elem, 0, free);
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
	(*obj)->del_fonction = fireball_player_del;
	if (game->player.orientation == O_RIGHT)
		(*obj)->x_speed = FB_SPEED_PLAYER;
	else
		(*obj)->x_speed = -FB_SPEED_PLAYER;
	(*obj)->y_speed = -FB_START_UP_SPEED;
	(*obj)->y_acceleration = 0.0;
}
