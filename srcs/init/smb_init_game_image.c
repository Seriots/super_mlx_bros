/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_game_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:44:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/22 12:37:44 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb_objects.h"
#include "smb.h"

static int	init_all_xpm_image(t_game *game)
{
	if (!init_xpm_image(game, &game->all_images.sign, SIGN_PATH)
		&& !init_xpm_image(game, &game->all_images.big_tree, BTR_PATH)
		&& !init_xpm_image(game, &game->all_images.block, BLK_PATH)
		&& !init_xpm_image(game, &game->all_images.end_bar, BAR_PATH)
		&& !init_xpm_image(game, &game->all_images.flag, FLAG_PATH)
		&& !init_xpm_image(game, &game->all_images.castle, CASTLE_PATH)
		&& !init_xpm_image(game, &game->all_images.fire_flower, FF_PATH)
		&& !init_xpm_image(game, &game->all_images.red_champi, REDC_PATH)
		&& !init_xpm_image(game, &game->all_images.loot_block, LB_PATH)
		&& !init_xpm_image(game, &game->all_images.loot_block_use, LBU_PATH)
		&& !init_xpm_image(game, &game->all_images.flower, FLOWER_PATH)
		&& !init_xpm_image(game, &game->all_images.little_tree, LTR_PATH)
		&& !init_xpm_image(game, &game->all_images.crate, CRATE_PATH))
		return (0);
	return (3);
}

int	init_game_images(t_game *game)
{
	if (!init_all_tiles(game)
		&& !init_all_little_player(game)
		&& !init_all_big_player(game)
		&& !init_all_fire_player(game)
		&& !init_images_group(game, COIN_PATH, COIN_NUMBER,
			&game->all_images.all_coins)
		&& !init_images_group(game, CHAR_PATH, CHAR_NUMBER,
			&game->all_images.all_characters)
		&& !init_images_group(game, GBA_PATH, GBA_NUMBER,
			&game->all_images.all_goombas)
		&& !init_images_group(game, PP_PATH, PP_NUMBER,
			&game->all_images.all_piranhas)
		&& !init_images_group(game, FB_PATH, FB_NUMBER,
			&game->all_images.all_fireballs)
		&& !init_images_group(game, BB_PATH, BB_NUMBER,
			&game->all_images.all_breakable_block)
		&& !init_images_group(game, PTS_PATH, PTS_NUMBER,
			&game->all_images.all_points)
		&& !init_all_xpm_image(game))
		return (0);
	return (3);
}
