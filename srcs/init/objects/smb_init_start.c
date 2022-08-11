/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:34:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 20:25:29 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"

void	init_start(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->animation_duration = 0;
	(*obj)->height = 0;
	(*obj)->width = 0;
	(*obj)->img = 0;
	(*obj)->is_collide = 0;
	(*obj)->is_visible = 0;
	(*obj)->is_strong = 0;
	(*obj)->nb_image = 0;
	(*obj)->start_frame = game->current_frame;
	(*obj)->col_fonction = 0;
	(*obj)->update_fonction = 0;
}
