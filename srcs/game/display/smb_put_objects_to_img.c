/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_put_objects_to_img.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:26:49 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/10 21:35:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

#include <stdio.h>

static void	put_object(t_game *game, t_object *obj, int position, t_img_data *img)
{
	unsigned int	color;
	char			*dst;
	int				x;
	int				y;

	(void)game;
	y = 0;
	while (y < obj->height)
	{
		x = 0;
		while (x < obj->width)
		{
			if (obj->x + x - position >= 0 && obj->x + x <= position + SCREEN_WIDTH
				&& obj->y + y >= 0 && obj->y + y <= SCREEN_HEIGHT)
			{
				dst = img->addr + ((int)(y + obj->y) * img->line_length
						+ (int)(x + obj->x - position) * (img->bits_per_pixel / 8));
				color = get_pxl_color(*(obj->img), x, y);
				if (*(unsigned int *)dst != color && color != 4278190080)
					*(unsigned int *)dst = color;
			}
			x++;
		}
		y ++;
	}
}

void	put_objects_to_image(t_game *game, t_dict *objects, int position, t_img_data *img)
{
	t_object *value;

	while (objects)
	{
		value = (t_object *)objects->value;
		if (value->is_visible && value->x < position + SCREEN_WIDTH && value->x + value->width > position)
			put_object(game, value, position, img);
		objects = objects->next;
	}
}
