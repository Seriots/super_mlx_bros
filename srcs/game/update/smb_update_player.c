/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:21:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 12:23:31 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

static int	update_little(t_game *game, t_player *player, int value)
{
	if (player->state == IDLE)
		change_image(game, player, value + 0);
	if (player->state == RUN)
		update_running_image(game, player, value + 0);
	if (player->state == UJUMP)
		change_image(game, player, value + 2);
	if (player->state == DJUMP)
		change_image(game, player, value + 3);
	if (player->state == CROUCH)
		change_image(game, player, value + 4);
	if (player->state == SLIDE)
		change_image(game, player, value + 5);
	if (player->state == BAR)
		change_image(game, player, value + 6);
	if (player->state == GROWTH)
		update_growth_image(game, player, value + 7);
	if (player->state == VICTORY)
		update_victory_image(game, player, value * 2);
	if (player->state == DEAD)
		update_dead_image(game, player, LPLAYER_NUMBER - 2);
	return (0);
}

static int	update_big(t_game *game, t_player *player, int value)
{
	if (player->state == IDLE)
		change_image(game, player, value + 0);
	if (player->state == RUN)
		update_running_image(game, player, value + 0);
	if (player->state == UJUMP)
		change_image(game, player, value + 3);
	if (player->state == DJUMP)
		change_image(game, player, value + 4);
	if (player->state == CROUCH)
		change_image(game, player, value + 5);
	if (player->state == SLIDE)
		change_image(game, player, value + 6);
	if (player->state == BAR)
		change_image(game, player, value + 7);
	if (player->state == SHRINK)
		update_growth_image(game, player, value + 8);
	if (player->state == GROWTH)
		update_growth_image(game, player, value + 11);
	if (player->state == VICTORY)
		update_victory_image(game, player, value * 2);
	return (0);
}

static int	update_fire(t_game *game, t_player *player, int value)
{
	if (player->state == IDLE)
		change_image(game, player, value + 0);
	if (player->state == RUN)
		update_running_image(game, player, value + 0);
	if (player->state == UJUMP)
		change_image(game, player, value + 3);
	if (player->state == DJUMP)
		change_image(game, player, value + 4);
	if (player->state == CROUCH)
		change_image(game, player, value + 5);
	if (player->state == SLIDE)
		change_image(game, player, value + 6);
	if (player->state == BAR)
		change_image(game, player, value + 7);
	if (player->state == SHRINK)
		update_growth_image(game, player, value + 8);
	if (player->state == VICTORY)
		update_victory_image(game, player, value * 2);
	return (0);
}

int	update_player_image(t_game *game, t_player *player)
{
	int	value;

	if (player->evolution == LITTLE)
		value = player->orientation * O_LITTLE;
	if (player->evolution == BIG)
		value = player->orientation * O_BIG;
	if (player->evolution == FIRE)
		value = player->orientation * O_FIRE;
	if (player->evolution == LITTLE)
		update_little(game, player, value);
	else if (player->evolution == BIG)
		update_big(game, player, value);
	else if (player->evolution == FIRE)
		update_fire(game, player, value);
	return (0);
}
