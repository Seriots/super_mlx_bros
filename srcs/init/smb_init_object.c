/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:50:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 00:13:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "dict.h"

#include "smb_objects.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdlib.h>

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
}

t_object	*obj_new(char *tag, float x, float y)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (0);
	if (tag)
		*obj = (t_object){.x = x, .y = y};
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
	return (dict_new("OBJ", object));
}
