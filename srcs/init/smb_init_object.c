/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:50:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 02:07:25 by lgiband          ###   ########.fr       */
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
}

t_object	*obj_new(char *tag, float x, float y)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (0);
	if (tag)
		*obj = (t_object){.x = x, .y = y, .col_count = 0};
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
	return (dict_new("OBJ", object));
}
