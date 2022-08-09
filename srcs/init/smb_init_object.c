/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:50:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/09 22:54:11 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "dict.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdlib.h>

static void	choose_obj(t_object **object, char *tag, float x, float y)
{
	if (!ft_strcmp(tag, START))
		init_start(object, x, y);
	else if (!ft_strcmp(tag, END))
		init_end(object, x, y);
}

t_object	*obj_new(char *tag, float x, float y)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (0);
	if (tag)
		choose_obj(&obj, tag, x, y);
	return (obj);
}

t_dict	*get_dict_new(char *tag, t_object *object)
{
	if (!ft_strcmp(tag, START))
		return (dict_new(START, object));
	else if (!ft_strcmp(tag, END))
		return (dict_new(END, object));
	else
		return (dict_new("OBJ", object));
}
