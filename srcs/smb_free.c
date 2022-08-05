/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:06:12 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 01:09:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "mlx.h"

#include "smb_settings.h"
#include "smb_struct.h"

#include <stdlib.h>

#include <stdio.h>

void	free_img_array(t_game *game, t_img_data *imgs, int number)
{
	int	i;

	i = 0;
	(void)game;
	while (i < number)
	{
		mlx_destroy_image(game->mlx.display, imgs[i].img);
		i++;
	}
	free(imgs);
}

void	free_all_image(t_game *game)
{
	if (game->all_images.all_tiles)
		free_img_array(game, game->all_images.all_tiles, TILES_NUMBER);
}

void	free_game(t_game *game)
{
	ft_free_tab(game->map.map_data);
	free_all_image(game);
	mlx_destroy_image(game->mlx.display, game->background.img);
	mlx_destroy_image(game->mlx.display, game->window_image.img);
	mlx_destroy_window(game->mlx.display, game->mlx.window);
	mlx_destroy_display(game->mlx.display);
	free(game->mlx.display);
}
