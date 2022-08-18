/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_collisions_player_obj.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 22:28:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/18 05:33:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

#include <math.h>

#include <stdio.h>
/*
* Return 1: Collide
* Return 0: No-Collide
*/
void	get_new_limit(t_game *game, t_object *val, t_hbox *p_hbox, int *retval)
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
	game->collide_obj.x = val->x;
	game->collide_obj.y = val->y;
	game->collide_obj.width = val->width;
	game->collide_obj.height = val->height;
	*retval = 1;
}

void	get_new_limit_wall(t_collisions value, t_hbox *p_hbox)
{
	if (p_hbox->direction == RIGHT && value.x < p_hbox->x_max)
		p_hbox->x_max = value.x + 1;
	if (p_hbox->direction == LEFT && value.x + value.width > p_hbox->x_min)
		p_hbox->x_min = value.x + value.width - 1;
	if (p_hbox->direction == UP && value.y + value.height < p_hbox->y_min)
		p_hbox->y_min = value.y + value.height - 1;
	if (p_hbox->direction == DOWN && value.y < p_hbox->y_max)
		p_hbox->y_max = value.y + 1;
}

int	check_collide(t_game *game, t_dict *all_obj, t_hbox *p_hbox)
{
	t_object	*value;
	int			ret_val;

	ret_val = 0;
	while (all_obj)
	{
		value = (t_object *)all_obj->value;
		if (((value->x > p_hbox->x_min && value->x < p_hbox->x_max)
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
				get_new_limit(game, value, p_hbox, &ret_val);
		}
		all_obj = all_obj->next;
	}
	return (ret_val);
}

void	apply_collide(t_game *game, t_dict *all_obj, t_hbox *p_hbox)
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
			if (value->is_collide)
				value->col_fonction(game, all_obj, value, p_hbox->direction);
		}
		all_obj = next;
	}
}

int	check_col_player_obj(t_game *game, float x_pos, float y_pos, float pos)
{
	t_hbox	p_hbox;
	int		ret_val;

	p_hbox.x_max = max((int)floor(game->player.x_pos + game->x_position
				+ game->player.width),
			(int)floor(x_pos + game->player.width + pos));
	p_hbox.x_min = min((int)floor(game->player.x_pos + game->x_position),
			(int)floor(x_pos + pos));
	p_hbox.y_max = max((int)floor(game->player.y_pos + game->player.height),
			(int)floor(y_pos + game->player.height));
	p_hbox.y_min = min((int)floor(game->player.y_pos), (int)floor(y_pos));
	p_hbox.direction = NONE;
	if (game->player.x_pos > x_pos || game->x_position > pos)
		p_hbox.direction = LEFT;
	else if (game->player.x_pos < x_pos || game->x_position < pos)
		p_hbox.direction = RIGHT;
	else if (game->player.y_pos > y_pos)
		p_hbox.direction = UP;
	else if (game->player.y_pos < y_pos)
		p_hbox.direction = DOWN;
	if (game->collide_obj.height != 0)
		get_new_limit_wall(game->collide_obj, &p_hbox);
	ret_val = check_collide(game, game->map.all_object, &p_hbox);
	apply_collide(game, game->map.all_object, &p_hbox);
	return (ret_val);
}
