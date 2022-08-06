/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_move_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:36:26 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 19:46:25 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"

/*
* -> First step: move the player until he reachs the middle of the screen
* -> Third step: move the background until it reachs the maximum
* -> Second step: move the player until he reaches the maximum
*/

static int	first_part(t_game *game, t_player *player)
{
	if (player->x_pos + PLAYER_SPEED > SCREEN_WIDTH / 2 - player->width / 2)
	{
		game->x_position += (player->x_pos + PLAYER_SPEED)
			- (SCREEN_WIDTH / 2 - player->width / 2);
		player->x_pos = SCREEN_WIDTH / 2 - player->width / 2;
	}
	else
		player->x_pos += PLAYER_SPEED;
	return (0);
}

static int	second_part(t_game *game, t_player *player)
{
	(void)game;
	if (player->x_pos + PLAYER_SPEED + player->width > SCREEN_WIDTH)
			player->x_pos = SCREEN_WIDTH - player->width;
	else
		player->x_pos += PLAYER_SPEED;
	return (0);
}

static int	third_part(t_game *game, t_player *player)
{
	if (game->x_position + PLAYER_SPEED <= game->map.width - SCREEN_WIDTH)
		game->x_position += PLAYER_SPEED;
	else
	{
		player->x_pos += (game->x_position + PLAYER_SPEED)
			- (game->map.width - SCREEN_WIDTH);
		game->x_position = game->map.width - SCREEN_WIDTH;
	}
	return (0);
}

int	move_right(t_game *game, t_player *player)
{
	if (player->x_pos < SCREEN_WIDTH / 2 - player->width / 2)
		first_part(game, player);
	else if (game->x_position == game->map.width - SCREEN_WIDTH)
		second_part(game, player);
	else
		third_part(game, player);
	return (0);
}
