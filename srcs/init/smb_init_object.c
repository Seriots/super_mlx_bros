/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:50:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 14:07:46 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "dict.h"

#include "smb_objects.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdlib.h>

#include <stdio.h>

void	set_object(t_game *game, char *key, t_object **object)
{
	if (!ft_strcmp(key, START))
		init_start(game, object);
	else if (!ft_strcmp(key, END))
		init_end(game, object);
	else if (!ft_strcmp(key, COIN))
		init_coin(game, object);
	else if (!ft_strcmp(key, SIGN))
		init_sign(game, object);
	else if (!ft_strcmp(key, BTR))
		init_btr(game, object);
	else if (!ft_strcmp(key, BLOCK))
		init_block(game, object);
	else if (!ft_strcmp(key, FLAG))
		init_flag(game, object);
	else if (!ft_strcmp(key, CASTLE))
		init_castle(game, object);
	else if (!ft_strcmp(key, FIRE_FLOWER))
		init_fire_flower(game, object);
	else if (!ft_strcmp(key, BREAKABLE_BLOCK))
		init_breakable_block(game, object);
	else if (!ft_strcmp(key, LOOT_BLOCK))
		init_loot_block(game, object);
	else if (!ft_strcmp(key, RED_CHAMP))
		init_red_champ(game, object);
	else if (!ft_strcmp(key, GOOMBA))
		init_goomba(game, object);
	else if (!ft_strcmp(key, PLANT_PIRANHA))
		init_plant_pirahna(game, object);
	else if (!ft_strcmp(key, FIREBALL))
		init_fireball(game, object);
	else if (!ft_strcmp(key, FIREBALL_PLAYER))
		init_fireball_player(game, object);
}

t_object	*obj_new(char *tag, float x, float y)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (0);
	if (tag)
		*obj = (t_object){.x = x, .y = y, .col_count = 0,
			.y_speed = 0.0, .y_acceleration = 0.0,
			.x_speed = 0.0, .col_object = {0}};
	return (obj);
}

t_dict	*get_dict_new(char *tag, t_object *object)
{
	if (!ft_strcmp(tag, START))
		return (dict_new(START, object));
	else if (!ft_strcmp(tag, END))
		return (dict_new(END, object));
	else if (!ft_strcmp(tag, COIN))
		return (dict_new(COIN, object));
	else if (!ft_strcmp(tag, SIGN))
		return (dict_new(SIGN, object));
	else if (!ft_strcmp(tag, BTR))
		return (dict_new(BTR, object));
	else if (!ft_strcmp(tag, BLOCK))
		return (dict_new(BLOCK, object));
	else if (!ft_strcmp(tag, FLAG))
		return (dict_new(FLAG, object));
	else if (!ft_strcmp(tag, CASTLE))
		return (dict_new(CASTLE, object));
	else if (!ft_strcmp(tag, FIRE_FLOWER))
		return (dict_new(FIRE_FLOWER, object));
	else if (!ft_strcmp(tag, LOOT_BLOCK))
		return (dict_new(LOOT_BLOCK, object));
	else if (!ft_strcmp(tag, BREAKABLE_BLOCK))
		return (dict_new(BREAKABLE_BLOCK, object));
	else if (!ft_strcmp(tag, RED_CHAMP))
		return (dict_new(RED_CHAMP, object));
	else if (!ft_strcmp(tag, GOOMBA))
		return (dict_new(GOOMBA, object));
	else if (!ft_strcmp(tag, PLANT_PIRANHA))
		return (dict_new(PLANT_PIRANHA, object));
	else if (!ft_strcmp(tag, FIREBALL))
		return (dict_new(FIREBALL, object));
	else if (!ft_strcmp(tag, FIREBALL_PLAYER))
		return (dict_new(FIREBALL_PLAYER, object));
	return (dict_new("OBJ", object));
}
