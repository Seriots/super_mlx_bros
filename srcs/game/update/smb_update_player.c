/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_update_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 18:21:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/13 21:03:01 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

#include <stdio.h>

static void	change_image(t_game *game, t_player *player, int value)
{
	(void)game;
	//t_img_data	pre_img;
	int			pre_h;
	int			new_h;
	
	pre_h = player->height;
	//pre_img = player->img_player;
	player->img_player = player->all_player_img[value];
	player->width = player->img_player.width;
	player->height = player->img_player.height;
	new_h = player->height;
	/*if ((pre_h > new_h) && check_collisions(game, player->x_pos, player->y_pos - (pre_h - new_h - 15), game->x_position))
	{
		player->img_player = pre_img;
		player->width = player->img_player.width;
		player->height = player->img_player.height;		
	}
	else if ((pre_h < new_h) && check_collisions(game, player->x_pos, player->y_pos + (pre_h - new_h - 15), game->x_position))
	{
		player->img_player = pre_img;
		player->width = player->img_player.width;
		player->height = player->img_player.height;		
	}*/
	if (pre_h != new_h)
		player->y_pos += (pre_h - new_h);
}

static int update_little(t_game *game, t_player *player, int value)
{
	if (player->state == IDLE)
		change_image(game, player, value + 0);
	if (player->state == RUN)
		change_image(game, player, value + 1);
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
		change_image(game, player, value + 1);
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
	//printf(">%f %f\n", player->y_pos, player->x_pos);
	return (0);

}