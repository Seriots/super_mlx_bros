/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_put_background_to_img.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 00:53:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 00:53:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "smb_settings.h"
#include "smb_struct.h"
#include "smb.h"

void	put_bg_to_image(t_game *game, int position, t_img_data *img)
{
	unsigned int	color;
	char			*dst;
	int				x;
	int				y;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			dst = img->addr + (y * img->line_length
					+ x * (img->bits_per_pixel / 8));
			color = get_pxl_color(game->background,
					(x + position) % game->background.width, y);
			if (*(unsigned int *)dst != color)
				*(unsigned int *)dst = color;
			x++;
		}
		y ++;
	}
}
