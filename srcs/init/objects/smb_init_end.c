/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:40:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/16 03:06:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdio.h>

static int get_end_score(t_game *game, t_player *player, t_object *obj)
{
	int	diff;
	
	(void)game;
	diff = obj->height - (player->y_pos - obj->y);
	return (diff);
}

int	end_collisions(t_game *game, t_dict *elem, t_object *obj, int direction)
{
	static int	first;
	t_dict		*flag;

	(void)direction;
	(void)elem;
	if (game->player.x_pos + game->x_position + game->player.width < (obj->x + obj->width / 2) - END_BAR_HBOX
	|| game->player.x_pos + game->x_position > (obj->x + obj->width / 2) + END_BAR_HBOX)
		return (0);
	if (first == 0)
	{
		game->update_fct = update_end;
		game->keypressed_fct = key_pressed_default;
		game->keyreleased_fct = key_released_default;
		game->player.score = get_end_score(game, &game->player, obj);
		flag = add_obj(FLAG, (obj->x + obj->width / 2) + END_BAR_HBOX, obj->y + obj->height - FALG_HEIGHT);
		init_flag(game, (t_object **)&flag->value);
		dict_add_back(&game->map.all_object, flag);
		first++;
	}
	return (0);
}

void	init_end(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->img = &game->all_images.end_bar;
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = end_collisions;
	(*obj)->update_fonction = 0;
	dict_add_back(&game->map.all_object, add_obj(BLOCK, (*obj)->x - 4, (*obj)->y + (*obj)->height));
}
