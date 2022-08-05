/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:03:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 22:42:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "smb_struct.h"

#include "mlx.h"

#include <stdio.h>

int	init_image(t_game *game, int width, int height, t_img_data *img)
{
	img->img = mlx_new_image(game->mlx.display, width, height);
	if (!img->img)
		return (3);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (mlx_destroy_image(game->mlx.display, img->img), 3);
	img->width = width;
	img->height = height;
	return (0);
}

int	init_xpm_image(t_game *game, t_img_data *img, char *name)
{
	img->img = mlx_xpm_file_to_image(game->mlx.display, name,
			&img->width, &img->height);
	if (!img->img)
		return (3);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (mlx_destroy_image(game->mlx.display, img->img), 3);
	return (0);
}
