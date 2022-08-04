/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:06:12 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 00:59:27 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "smb_struct.h"

#include <stdlib.h>

void	free_game(t_game *game)
{
	mlx_destroy_image(game->mlx.display, game->background.img);
	mlx_destroy_image(game->mlx.display, game->window_image.img);
	mlx_destroy_window(game->mlx.display, game->mlx.window);
	mlx_destroy_display(game->mlx.display);
	free(game->mlx.display);
}
