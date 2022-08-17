/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_growth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:48:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 05:03:05 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

static int	get_new_state(t_game *game)
{
	if (game->player.evolution == LITTLE && game->player.state == GROWTH)
	{
		game->player.all_player_img = game->all_images.all_big_players;
		game->player.evolution = BIG;
	}
	else if (game->player.evolution == BIG && game->player.state == SHRINK)
	{
		game->player.all_player_img = game->all_images.all_little_players;
		game->player.evolution = LITTLE;
	}
	return (0);
}

int	update_growth(t_game *game)
{
	update_player_image(game, &game->player);
	if (game->update_fct != update_growth)
		get_new_state(game);
	return (0);
}
