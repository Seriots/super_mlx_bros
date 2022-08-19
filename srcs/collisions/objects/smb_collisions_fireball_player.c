/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_fireball_player.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:28:40 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 11:32:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"
#include "smb_objects.h"

#include <stdlib.h>

#include <math.h>

int	apply_collide_fireball(t_game *game, t_dict *all_obj, t_hbox *p_hbox)
{
	t_object	*value;
	t_dict		*next;

	while (all_obj)
	{
		next = all_obj->next;
		value = (t_object *)all_obj->value;
		if (((value->x > p_hbox->x_min && value->x < p_hbox->x_max)
				|| (value->x + value->width > p_hbox->x_min
					&& value->x + value->width < p_hbox->x_max)
				|| (value->x <= p_hbox->x_min
					&& value->x + value->width >= p_hbox->x_max))
			&& ((value->y > p_hbox->y_min && value->y < p_hbox->y_max)
				|| (value->y <= p_hbox->y_min
					&& value->y + value->height >= p_hbox->y_max)
				|| (value->y + value->height > p_hbox->y_min
					&& value->y + value->height < p_hbox->y_max)))
		{
			if (!ft_strcmp(all_obj->key, PLANT_PIRANHA) || !ft_strcmp(all_obj->key, GOOMBA))
			{
				dict_delone(&game->map.all_object, all_obj, 0, free);
				return (1);
			}
		}
		all_obj = next;
	}
	return (0);
}

int	check_col_all_obj_fireball(t_game *game, t_object *obj, float x_pos, float y_pos)
{
	t_hbox	p_hbox;
	int		ret_val;

	p_hbox.x_max = max((int)floor(obj->x + obj->width), (int)floor(x_pos + obj->width));
	p_hbox.x_min = min((int)floor(obj->x), (int)floor(x_pos));
	p_hbox.y_max = max((int)floor(obj->y + obj->height), (int)floor(y_pos + obj->height));
	p_hbox.y_min = min((int)floor(obj->y), (int)floor(y_pos));
	p_hbox.direction = NONE;
	if (obj->x > x_pos)
		p_hbox.direction = LEFT;
	else if (obj->x < x_pos)
		p_hbox.direction = RIGHT;
	else if (obj->y > y_pos)
		p_hbox.direction = UP;
	else if (obj->y < y_pos)
		p_hbox.direction = DOWN;
	if (obj->col_object.height != 0)
		get_new_limit_wall(obj->col_object, &p_hbox);
	ret_val = check_collide_obj(game, obj, game->map.all_object, &p_hbox);
	if (apply_collide_fireball(game, game->map.all_object, &p_hbox))
		return (2);
	return (ret_val);
}

int	check_collisions_fireball(t_game *game, t_object *obj, float x_pos, float y_pos)
{
	int	collide;

	obj->col_object = (t_collisions){.x = 0, .y = 0, .width = 0, .height = 0};
	collide = check_col_obj_map(game, obj, x_pos, y_pos);
	if (!collide)
		collide = check_col_all_obj_fireball(game, obj, x_pos, y_pos);
	return (collide);
}
