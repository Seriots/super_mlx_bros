/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_breakable_block.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:09:18 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 18:00:39 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb_objects.h"
#include "smb.h"

#include <stdlib.h>

int	breakable_block_collisions(t_game *game, t_object *obj, int direction)
{
	(void)game;
	(void)obj;
	if (!check_hbox(game, obj, BB_HBOX, obj->height / 2) || game->player.y_speed > 0.5 || game->player.state == CROUCH)
		return (0);
	if (direction == UP)
		obj->update_fonction = obj->del_fonction;
	return (0);
}

int	break_block_update(t_game *game, t_dict *elem, t_object *obj)
{
	int i;

	(void)elem;
	i = 0;
	while (i < game->delay)
	{
		obj->x += obj->x_speed;
		obj->y_acceleration += BBM_GRAVITY;
		obj->y_speed += obj->y_acceleration;
		if (obj->y_speed > BBM_Y_MAX_SPEED)
			obj->y_speed = BBM_Y_MAX_SPEED;
		obj->y += obj->y_speed;
		i++;
	}
	if (obj->y > SCREEN_HEIGHT)
		obj->update_fonction = obj->del_fonction;
	return (0);
}

int break_block_del(t_game *game, t_dict *elem, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_break(t_game *game, t_object **obj, float y_speed, int n)
{
	(*obj)->all_img = game->all_images.all_breakable_block;
	(*obj)->img = &(*obj)->all_img[n];
	(*obj)->width = (*obj)->img->width;
	(*obj)->height = (*obj)->img->height;
	(*obj)->is_collide = 0;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = 0;
	(*obj)->update_fonction = break_block_update;
	(*obj)->del_fonction = break_block_del;
	(*obj)->y_speed = -y_speed;
	if (n == 1)
		(*obj)->x_speed = BBM_X_SPEED1;
	if (n == 2)
		(*obj)->x_speed = -BBM_X_SPEED1;
	if (n == 3)
		(*obj)->x_speed = BBM_X_SPEED2;
	if (n == 4)
		(*obj)->x_speed = -BBM_X_SPEED2;
}

int	init_break_block(t_game *game, t_object *obj, float y_speed, int n)
{
	t_dict		*new;

	new = add_obj(BREAK_MOR, obj->x, obj->y);
	init_break(game, (t_object **)&new->value, y_speed, n);
	dict_add_back(&game->map.all_object, new);
	return (0);
}

int	breakable_block_del(t_game *game, t_dict *elem, t_object *obj)
{
	init_break_block(game, obj, BBM_Y_SPEED1, 1);
	init_break_block(game, obj, BBM_Y_SPEED1, 2);
	init_break_block(game, obj, BBM_Y_SPEED2, 3);
	init_break_block(game, obj, BBM_Y_SPEED2, 4);
	dict_delone(&game->map.all_object, elem, 0, free);
	return (0);
}

void	init_breakable_block(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_breakable_block;
	(*obj)->img = &game->all_images.all_breakable_block[0];
	(*obj)->animation_duration = 0;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 1;
	(*obj)->nb_image = 1;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = breakable_block_collisions;
	(*obj)->update_fonction = 0;
	(*obj)->del_fonction = breakable_block_del;
}
