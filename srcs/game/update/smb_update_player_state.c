/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_player_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:11:28 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/14 16:02:08 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdio.h>

static void update_orientation(t_player *player)
{
	if (player->left == 1)
		player->orientation = O_LEFT;
	else if (player->right == 1)
		player->orientation = O_RIGHT;
}

static void update_state(t_game *game, t_player *player)
{
	if (player->state == DEAD)
		return ;
	else if (player->bottom == 1 || (player->state == CROUCH
		&& check_collisions(game, player->x_pos,
			player->y_pos - 10, game->x_position))
		|| (player->state == CROUCH
			&& !check_collisions_bottom(game, player->x_pos,
				player->y_pos, game->x_position)))
		player->state = CROUCH;
	else if (player->y_speed != 0)
	{
		if (player->y_speed > V_DOWN_MAX / 2)
			player->state = UJUMP;
		else
			player->state = DJUMP;
	}
	else if ((player->left == 1 && player->x_speed > 0) || (player->right == 1 && player->x_speed < 0))
		player->state = SLIDE;
	else if (player->left == 1 || player->right == 1)
	{
		if (player->state != RUN)
			player->anim_frame_start = game->current_frame;
		player->state = RUN;
		player->anim_duration = 200;
		if (player->evolution == LITTLE)
			player->anim_length = 2;
		else
			player->anim_length = 3;
	}
	else
		player->state = IDLE;
}

int	update_player_state(t_game *game, t_player *player)
{
	update_orientation(player);
	update_state(game, player);	
	return (0);

}