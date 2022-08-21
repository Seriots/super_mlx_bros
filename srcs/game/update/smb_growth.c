/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_growth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:48:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/21 18:42:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdio.h>

static int	get_new_state(t_game *game)
{
	if (game->player.evolution == LITTLE
		&& (game->player.state == GROWTH || game->player.state == C_GROWTH))
	{
		game->player.all_player_img = game->all_images.all_bplyrs;
		game->player.evolution = BIG;
	}
	else if (game->player.evolution == BIG
		&& (game->player.state == SHRINK || game->player.state == C_SHRINK))
	{
		game->player.all_player_img = game->all_images.all_lplyrs;
		game->player.evolution = LITTLE;
	}
	else if (game->player.evolution == BIG
		&& (game->player.state == GROWTH || game->player.state == C_GROWTH))
	{
		game->player.all_player_img = game->all_images.all_fplyrs;
		game->player.evolution = FIRE;
	}
	else if (game->player.evolution == FIRE
		&& (game->player.state == SHRINK || game->player.state == C_SHRINK))
	{
		game->player.all_player_img = game->all_images.all_bplyrs;
		game->player.evolution = BIG;
	}
	return (0);
}

int	growth(t_game *game)
{
	if (game->player.state == CROUCH)
		game->player.anim_length = 1;
	else
		game->player.anim_length = 3;
	game->player.anim_duration = PLAYER_GROWTH_ANIM_SPEED;
	game->player.anim_frame_start = game->current_frame;
	game->update_fct = update_growth;
	return (0);
}

int	shrink(t_game *game)
{
	if (game->player.evolution > LITTLE)
	{
		if (game->player.state == CROUCH)
			game->player.anim_length = 1;
		else
			game->player.anim_length = 3;
		game->update_fct = update_shrink;
		game->player.anim_duration = PLAYER_GROWTH_ANIM_SPEED / 2;
		game->player.anim_frame_start = game->current_frame;
	}
	else
	{
		game->update_fct = update_death;
		game->player.state = DEAD;
		game->keypressed_fct = 0;
		game->keyreleased_fct = 0;
		game->player.anim_length = 2;
		game->player.anim_duration = PLAYER_DEAD_ANIM_DURATION;
		game->player.anim_frame_start = game->current_frame;
	}
	game->player.invincible_frame = PLAYER_INVINCIBLE_DURATION;
	return (0);
}

int	update_growth(t_game *game)
{
	if (game->player.state == CROUCH || game->player.state == C_GROWTH)
		game->player.state = C_GROWTH;
	else
		game->player.state = GROWTH;
	update_player_image(game, &game->player);
	if (game->update_fct != update_growth)
		get_new_state(game);
	return (0);
}

int	update_shrink(t_game *game)
{
	if (game->player.state == CROUCH || game->player.state == C_SHRINK)
		game->player.state = C_SHRINK;
	else
		game->player.state = SHRINK;
	update_player_image(game, &game->player);
	if (game->update_fct != update_shrink)
	{
		get_new_state(game);
		if (game->player.state == C_GROWTH || game->player.state == C_SHRINK)
			game->player.state = CROUCH;
	}
	return (0);
}
