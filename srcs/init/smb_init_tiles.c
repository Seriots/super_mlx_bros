/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:33:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/13 16:18:11 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

#include "mlx.h"

#include <stdlib.h>

#include <stdio.h>

static void	make_name(char *all_path, const char *name)
{
	int	j;
	int	i;

	i = 0;
	while (i < TILES_PATH_SIZE + TILES_MAX_NAME_SIZE && TILES_PATH[i])
	{
		all_path[i] = TILES_PATH[i];
		i++;
	}
	j = 0;
	while (i < TILES_PATH_SIZE + TILES_MAX_NAME_SIZE && name[j])
	{
		all_path[i] = name[j];
		j++;
		i++;
	}
	all_path[i] = 0;
}

int	init_all_tiles(t_game *game)
{
	int			err;
	char		name[TILES_PATH_SIZE + TILES_MAX_NAME_SIZE];
	int			i;
	const char	*all_name[] = {
		"tile_TBRL.xpm", "tile_NONE.xpm", "tile_B.xpm", "tile_BL.xpm",
		"tile_BLR.xpm", "tile_BR.xpm", "tile_L.xpm", "tile_R.xpm",
		"tile_RL.xpm", "tile_T.xpm", "tile_TB.xpm", "tile_TBL.xpm",
		"tile_TBR.xpm", "tile_TL.xpm", "tile_TR.xpm", "tile_TRL.xpm",};

	game->all_images.all_tiles = ft_calloc(sizeof(t_img_data), TILES_NUMBER);
	if (!game->all_images.all_tiles)
		return (9);
	i = 0;
	while (i < TILES_NUMBER)
	{
		make_name(name, all_name[i]);
		err = init_xpm_image(game, &game->all_images.all_tiles[i], name);
		if (err)
			return (free_img_array(game, &game->all_images.all_tiles, i), err);
		i++;
	}
	return (0);
}
