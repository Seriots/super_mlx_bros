/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:06:12 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 11:41:11 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "mlx.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb_objects.h"

#include <stdlib.h>

#include <stdio.h>

void	free_img_array(t_game *game, t_img_data **imgs_ptr, int number)
{
	int			i;
	t_img_data	*imgs;

	i = 0;
	imgs = *imgs_ptr;
	(void)game;
	while (i < number)
	{
		mlx_destroy_image(game->mlx.display, imgs[i].img);
		i++;
	}
	free(imgs);
	*imgs_ptr = NULL;
}

void	free_all_image(t_game *game)
{
	if (game->all_images.all_tiles)
		free_img_array(game, &game->all_images.all_tiles, TILES_NUMBER);
	if (game->all_images.all_little_players)
		free_img_array(game, &game->all_images.all_little_players,
			LPLAYER_NUMBER);
	if (game->all_images.all_fire_players)
		free_img_array(game, &game->all_images.all_fire_players, FPLAYER_NUMBER);
	if (game->all_images.all_big_players)
		free_img_array(game, &game->all_images.all_big_players, BPLAYER_NUMBER);
	if (game->all_images.all_coins)
		free_img_array(game, &game->all_images.all_coins, COIN_NUMBER);
	if (game->all_images.all_characters)
		free_img_array(game, &game->all_images.all_characters, CHAR_NUMBER);
	if (game->all_images.all_goombas)
		free_img_array(game, &game->all_images.all_goombas, GBA_NUMBER);
	if (game->all_images.all_piranhas)
		free_img_array(game, &game->all_images.all_piranhas, PP_NUMBER);
	if (game->all_images.all_fireballs)
		free_img_array(game, &game->all_images.all_fireballs, FB_NUMBER);
	mlx_destroy_image(game->mlx.display, game->all_images.sign.img);
	mlx_destroy_image(game->mlx.display, game->all_images.big_tree.img);
	mlx_destroy_image(game->mlx.display, game->all_images.end_bar.img);
	mlx_destroy_image(game->mlx.display, game->all_images.block.img);
	mlx_destroy_image(game->mlx.display, game->all_images.castle.img);
	mlx_destroy_image(game->mlx.display, game->all_images.flag.img);
	mlx_destroy_image(game->mlx.display, game->all_images.fire_flower.img);
	mlx_destroy_image(game->mlx.display, game->all_images.red_champi.img);
	mlx_destroy_image(game->mlx.display, game->all_images.loot_block.img);
	mlx_destroy_image(game->mlx.display, game->all_images.loot_block_use.img);
	mlx_destroy_image(game->mlx.display, game->all_images.breakable_block.img);
}

void	free_all_object(t_game *game)
{
	dict_clear(game->map.all_object, 0, free);
}

void	free_game(t_game *game)
{
	ft_free_tab(game->map.map_data);
	free_all_image(game);
	free_all_object(game);
	mlx_destroy_image(game->mlx.display, game->background.img);
	mlx_destroy_image(game->mlx.display, game->window_image.img);
	mlx_destroy_window(game->mlx.display, game->mlx.window);
	mlx_destroy_display(game->mlx.display);
	free(game->mlx.display);
}
