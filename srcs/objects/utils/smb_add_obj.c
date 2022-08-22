/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_add_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:38:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/22 11:49:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb.h"

#include <stdlib.h>

t_dict	*add_obj(char *tag, int x, int y)
{
	t_dict		*dict;
	t_object	*object;

	dict = 0;
	object = obj_new(tag, x, y);
	if (object)
		dict = get_dict_new(tag, object);
	if (!dict && object)
		return (free(object), (void *)0);
	return (dict);
}

t_dict	*add_obj_parsing(char *tag, t_object obj)
{
	t_dict		*dict;
	t_object	*object;

	dict = 0;
	object = obj_new(tag, obj.x, obj.y);
	if (object)
		dict = get_dict_new(tag, object);
	if (!dict && object)
		return (free(object), (void *)0);
	return (dict);
}
