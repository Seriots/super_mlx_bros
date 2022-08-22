/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:50:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/22 12:07:21 by lgiband          ###   ########.fr       */
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
	long unsigned int	i;
	const t_init		all_tag[][2] = {{{START, init_start}},
	{{COIN, init_coin}}, {{SIGN, init_sign}}, {{BLOCK, init_block}},
	{{FLAG, init_flag}}, {{CASTLE, init_castle}}, {{END, init_end}},
	{{FIRE_FLOWER, init_fire_flower}}, {{GOOMBA, init_goomba}},
	{{BREAKABLE_BLOCK, init_breakable_block}}, {{BTR, init_btr}},
	{{LOOT_BLOCK, init_loot_block}}, {{PLANT_PIRANHA, init_plant_pirahna}},
	{{CRATE, init_crate}}, {{RED_CHAMP, init_red_champ}},
	{{FIREBALL, init_fireball}}, {{FIREBALL_PLAYER, init_fireball_player}},
	{{FLOWER, init_flower}}, {{LTR, init_ltr}}};

	i = 0;
	while (i < sizeof(all_tag) / sizeof(all_tag[0]))
	{
		if (!ft_strcmp(key, all_tag[i]->tag))
			return (all_tag[i]->fct(game, object));
		i++;
	}
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
	long unsigned int	i;
	static char			all_tag[][6] = {START, END, COIN, SIGN, BTR, BLOCK,
		FLAG, CASTLE, FIRE_FLOWER, BREAKABLE_BLOCK, LOOT_BLOCK, RED_CHAMP,
		GOOMBA, PLANT_PIRANHA, FIREBALL, FIREBALL_PLAYER, CRATE, BREAK_MOR,
		FLOWER, LTR};

	i = 0;
	while (i < sizeof(all_tag) / sizeof(all_tag[0]))
	{
		if (!ft_strcmp(tag, all_tag[i]))
			return (dict_new(all_tag[i], object));
		i++;
	}
	return (0);
}
