/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_coin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:29:47 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/09 22:58:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"

void	init_coin(t_object **obj, float x, float y)
{
	(*obj)->x = x;
	(*obj)->y = y;
	(*obj)->all_img = 0;
	(*obj)->animation_duration = 0;
	(*obj)->height = 0;
	(*obj)->width = 0;
	(*obj)->img = 0;
	(*obj)->is_collide = 0;
	(*obj)->is_visible = 0;
	(*obj)->nb_image = 0;
	(*obj)->start_frame = 0;
}