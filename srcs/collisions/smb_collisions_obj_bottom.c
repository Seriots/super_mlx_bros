/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_obj_bottom.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:18:45 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:50:30 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

#include <math.h>

int	check_collide_bottom_obj(t_game *game, t_dict *all_obj,
		t_hbox *p_hbox, t_object *obj)
{
	t_object	*value;

	(void)game;
	while (all_obj)
	{
		value = (t_object *)all_obj->value;
		if ((value != obj)
			&& ((value->x > p_hbox->x_min && value->x < p_hbox->x_max)
				|| (value->x + value->width > p_hbox->x_min
					&& value->x + value->width < p_hbox->x_max)
				|| (value->x <= p_hbox->x_min
					&& value->x + value->width >= p_hbox->x_max))
			&& ((value->y > p_hbox->y_min && value->y < p_hbox->y_max)
				|| (value->y + value->height > p_hbox->y_min
					&& value->y + value->height < p_hbox->y_max)
				|| (value->y <= p_hbox->y_min
					&& value->y + value->height >= p_hbox->y_max)))
		{
			if (value->is_strong)
				return (1);
		}
		all_obj = all_obj->next;
	}
	return (0);
}

int	check_col_obj_bottom(t_game *game, t_object *obj, float x_pos, float y_pos)
{
	t_hbox	p_hbox;

	p_hbox.x_max = max((int)floor(obj->x + obj->width),
			(int)floor(x_pos + obj->width));
	p_hbox.x_min = min((int)floor(obj->x),
			(int)floor(x_pos));
	p_hbox.y_max = max((int)floor(obj->y + obj->height),
			(int)floor(y_pos + obj->height));
	p_hbox.y_min = min((int)floor(obj->y), (int)floor(y_pos));
	p_hbox.direction = DOWN;
	return (check_collide_bottom_obj(game, game->map.all_object, &p_hbox, obj));
}

int	check_collisions_bottom_obj(t_game *game, t_object *obj,
		float x_pos, float y_pos)
{
	t_collisions	col;
	int				j;

	col.x = (int)floor(x_pos);
	col.y = (int)floor(y_pos + 1);
	col.width = ((col.x + obj->width - 1) / TILES_SIZE)
		- (col.x / TILES_SIZE) + 1;
	col.height = ((col.y + obj->height - 1) / TILES_SIZE)
		- (col.y / TILES_SIZE) + 1;
	col.x = col.x / TILES_SIZE;
	col.y = col.y / TILES_SIZE;
	j = 0;
	while (j < col.width)
	{
		if (is_in_map(game, col.x + j, col.y + col.height - 1))
		{
			if (check_col_obj_bottom(game, obj, x_pos, y_pos + 1)
				|| game->map.map_data[col.y + col.height - 1][col.x + j] != '0')
				return (1);
		}
		j++;
	}
	return (0);
}
