/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_player_state.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 19:11:28 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 19:22:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdio.h>

static void	update_orientation(t_player *player)
{
	if (player->left == 1)
		player->orientation = O_LEFT;
	else if (player->right == 1)
		player->orientation = O_RIGHT;
}

static void	state_run(t_game *game, t_player *player)
{
	if (player->state != RUN)
		player->anim_frame_start = game->current_frame;
	player->state = RUN;
	player->anim_duration = PLAYER_RUN_ANIM_SPEED;
	if (player->evolution == LITTLE)
		player->anim_length = 2;
	else
		player->anim_length = 3;
}

static void	state_jump(t_game *game, t_player *player)
{
	(void)game;
	if (player->y_speed > V_DOWN_MAX / 2)
		player->state = UJUMP;
	else
		player->state = DJUMP;
}

static void	update_state(t_game *game, t_player *player)
{
	int	crouch_check;
;
	if (player->evolution > LITTLE)
		crouch_check = 13;
	else
		crouch_check = 6;
	if (player->state == DEAD)
		return ;
	else if (player->bottom == 1 || (player->state == CROUCH
			&& check_collisions(game, player->x_pos,
				player->y_pos - crouch_check, game->x_position))
		|| (player->state == CROUCH
			&& !check_collisions_bottom(game, player->x_pos,
				player->y_pos, game->x_position)))
		player->state = CROUCH;
	else if (player->y_speed != 0)
		state_jump(game, player);
	else if ((player->left == 1 && player->x_speed > 0)
		|| (player->right == 1 && player->x_speed < 0))
		player->state = SLIDE;
	else if (player->left == 1 || player->right == 1)
		state_run(game, player);
	else
		player->state = IDLE;
}

int	update_player_state(t_game *game, t_player *player)
{
	update_orientation(player);
	update_state(game, player);
	if (player->invincible_frame > 0)
		player->invincible_frame -= game->delay;
	if (player->invincible_frame < 0)
		player->invincible_frame = 0;
	if (player->fireball_frame > 0)
		player->fireball_frame -= game->delay;
	if (player->fireball_frame < 0)
		player->fireball_frame = 0;
	return (0);
}
