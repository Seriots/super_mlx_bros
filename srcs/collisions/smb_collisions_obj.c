/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_obj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:35:29 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:49:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

#include <math.h>

void	get_new_limit_obj(t_object *obj, t_object *val,
	t_hbox *p_hbox, int *retval)
{
	if (p_hbox->direction == RIGHT && val->x < p_hbox->x_max)
		p_hbox->x_max = val->x + 1;
	else if (p_hbox->direction == LEFT && val->x + val->width > p_hbox->x_min)
		p_hbox->x_min = val->x + val->width - 1;
	else if (p_hbox->direction == UP && val->y + val->height > p_hbox->y_min)
		p_hbox->y_min = val->y + val->height - 1;
	else if (p_hbox->direction == DOWN && val->y < p_hbox->y_max)
		p_hbox->y_max = val->y + 1;
	else
		return ;
	obj->col_object.x = val->x;
	obj->col_object.y = val->y;
	obj->col_object.width = val->width;
	obj->col_object.height = val->height;
	obj->col_object.direction = p_hbox->direction;
	*retval = 1;
}

int	check_collide_obj(t_object *obj, t_dict *all_obj, t_hbox *p_hbox)
{
	t_object	*value;
	int			ret_val;

	ret_val = 0;
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
				get_new_limit_obj(obj, value, p_hbox, &ret_val);
		}
		all_obj = all_obj->next;
	}
	return (ret_val);
}

int	check_col_all_obj(t_game *game, t_object *obj, float x_pos, float y_pos)
{
	t_hbox	p_hbox;
	int		ret_val;

	p_hbox.x_max = max((int)floor(obj->x + obj->width),
			(int)floor(x_pos + obj->width));
	p_hbox.x_min = min((int)floor(obj->x), (int)floor(x_pos));
	p_hbox.y_max = max((int)floor(obj->y + obj->height),
			(int)floor(y_pos + obj->height));
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
	ret_val = check_collide_obj(obj, game->map.all_object, &p_hbox);
	return (ret_val);
}

int	check_collisions_obj(t_game *game, t_object *obj, float x_pos, float y_pos)
{
	int	collide;

	obj->col_object = (t_collisions){.x = 0, .y = 0, .width = 0, .height = 0};
	collide = check_col_obj_map(game, obj, x_pos, y_pos);
	if (!collide)
		collide = check_col_all_obj(game, obj, x_pos, y_pos);
	return (collide);
}
