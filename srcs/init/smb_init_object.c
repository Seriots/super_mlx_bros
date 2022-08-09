/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:50:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/08 23:20:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "dict.h"

#include "smb_settings.h"
#include "smb_struct.h"

#include <stdlib.h>

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
	else
		return (dict_new("OBJ", object));
}
