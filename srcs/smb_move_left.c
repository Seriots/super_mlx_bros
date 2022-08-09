/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_move_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:35:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/09 15:39:35 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <math.h>

#include <stdio.h>

static int	first_part(t_game *game, t_player *player)
{
	if (check_collisions(game, player->x_pos - (game->delay_between_frame * PLAYER_SPEED),
			player->y_pos, game->x_position))
		player->x_pos = game->collide_obj.x + game->collide_obj.width - game->x_position;
	else if (player->x_pos - (game->delay_between_frame * PLAYER_SPEED)
		< SCREEN_WIDTH / 2 - player->width / 2)
		player->x_pos = SCREEN_WIDTH / 2 - player->width / 2;
	else
		player->x_pos -= (game->delay_between_frame * PLAYER_SPEED);
	return (0);
}

static int	second_part(t_game *game, t_player *player)
{
	if (check_collisions(game, player->x_pos - (game->delay_between_frame * PLAYER_SPEED),
			player->y_pos, game->x_position))
		player->x_pos = game->collide_obj.x + game->collide_obj.width - game->x_position;
	else if (player->x_pos - (game->delay_between_frame * PLAYER_SPEED) < 0)
		player->x_pos = 0;
	else
		player->x_pos -= game->delay_between_frame * PLAYER_SPEED;
	return (0);
}

static int	third_part(t_game *game, t_player *player)
{
	if (check_collisions(game, player->x_pos, player->y_pos,
			game->x_position - (game->delay_between_frame * PLAYER_SPEED)))
		game->x_position = game->collide_obj.x + game->collide_obj.width - player->x_pos;
	else if (game->x_position - (game->delay_between_frame * PLAYER_SPEED) >= 0)
		game->x_position -= (game->delay_between_frame * PLAYER_SPEED);
	else
	{
		player->x_pos += (game->x_position - (game->delay_between_frame * PLAYER_SPEED));
		game->x_position = 0;
	}
	if (game->x_position < 0)
		game->x_position = 0;
	return (0);
}

int	move_left(t_game *game, t_player *player)
{
	if (player->x_pos > SCREEN_WIDTH / 2 - player->width / 2)
		first_part(game, player);
	else if (game->x_position == 0)
		second_part(game, player);
	else
		third_part(game, player);
	return (0);
}
