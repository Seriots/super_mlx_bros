/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_coin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:29:47 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 00:14:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"
#include "smb_objects.h"
#include "smb_objects_fonction.h"

#include <stdio.h>

int	coin_collisions(t_game *game, t_object *obj, int direction)
{
	(void)game;
	(void)direction;
	printf("collisions coin %f %f\n", obj->x, obj->y);
	return (0);
}

void	init_coin(t_game *game, t_object **obj)
{
	(*obj)->all_img = game->all_images.all_coins;
	(*obj)->img = &game->all_images.all_coins[0];
	(*obj)->animation_duration = COIN_ANIM_DURATION;
	(*obj)->height = (*obj)->img->height;
	(*obj)->width = (*obj)->img->width;
	(*obj)->is_collide = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = COIN_NUMBER;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = coin_collisions;
}