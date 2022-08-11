/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:03:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 20:23:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_struct.h"
#include "smb.h"
#include "smb_objects.h"

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

static int	ft_nbrlen(int num)
{
	int	result;

	result = 0;
	while (num > 9)
	{
		result++;
		num /= 10;
	}
	return (result);
}

static void	make_image_path(char *name, char *path, int number)
{
	char	strnum[11];
	int		i;
	int		j;

	i = ft_nbrlen(number);
	strnum[i + 1] = 0;
	while (i >= 0)
	{
		strnum[i] = (number % 10) + 48;
		number /= 10;
		i--;
	}
	i = 0;
	while (path[i])
	{
		name[i] = path[i];
		i++;
	}
	j = 0;
	while (strnum[j])
		name[i++] = strnum[j++];
	j = 0;
	while (IMAGE_EXTENSION[j])
		name[i++] = IMAGE_EXTENSION[j++];
	name[i] = 0;
}

int	init_images_group(t_game *game, char *path,
	int nb_of_images, t_img_data **dst_ptr)
{
	int			error;
	char		name[NAME_BUFFER_SIZE + 1];
	int			i;

	*dst_ptr = ft_calloc(sizeof(t_img_data), nb_of_images);
	if (!game->all_images.all_tiles)
		return (9);
	i = 0;
	while (i < nb_of_images)
	{
		make_image_path(name, path, i);
		error = init_xpm_image(game, &((*dst_ptr)[i]), name);
		if (error)
			return (free_img_array(game, dst_ptr, i), error);
		i++;
	}
	return (0);
}
