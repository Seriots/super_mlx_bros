/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:21:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/14 01:12:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdio.h>

static void	change_image(t_game *game, t_player *player, int value)
{
	int			pre_h;
	int			new_h;
	
	(void)game;
	pre_h = player->height;
	player->img_player = player->all_player_img[value];
	player->width = player->img_player.width;
	player->height = player->img_player.height;
	new_h = player->height;
	if (pre_h != new_h)
		player->y_pos += (pre_h - new_h);
}

static int update_running_image(t_game *game, t_player *player, int value)
{
	int cur_frame;
	int image_value;

	cur_frame = (game->current_frame - player->anim_frame_start) % player->anim_duration;
	image_value = cur_frame / (player->anim_duration / player->anim_length);
	if (image_value >= player->anim_length)
		image_value = player->anim_length - 1;
	change_image(game, player, value + image_value);
	return (0);
}

static int update_little(t_game *game, t_player *player, int value)
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
	return (0);
}

static int update_big(t_game *game, t_player *player, int value)
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
	return (0);
}

int	update_player_image(t_game *game, t_player *player)
{
	int value;

	if (player->evolution == LITTLE)
		value = player->orientation * 5;
	if (player->evolution == BIG)
		value = player->orientation * 6;
	if (player->evolution == SPECIAL)
		value = player->orientation * 6;
	if (player->evolution == LITTLE)
		update_little(game, player, value);
	else if (player->evolution == BIG)
		update_big(game, player, value);
	return (0);

}