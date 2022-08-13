/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:10:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/13 17:06:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "mlx.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

static void	make_name_player(char *all_path, const char *name, char *path, int size_path)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (i < size_path + ft_strlen(name) && path[i])
	{
		all_path[i] = path[i];
		i++;
	}
	j = 0;
	while (i < size_path + ft_strlen(name) && name[j])
	{
		all_path[i] = name[j];
		j++;
		i++;
	}
	all_path[i] = 0;
}

int	init_all_little_player(t_game *game)
{
	int			err;
	char		name[LPLAYER_PATH_SIZE + LPLAYER_MAX_NAME_SIZE];
	int			i;
	const char	*all_name[] = {
		"tile_TBRL.xpm", "tile_NONE.xpm", "tile_B.xpm", "tile_BL.xpm",
		"tile_BLR.xpm", "tile_BR.xpm", "tile_L.xpm", "tile_R.xpm",
		"tile_RL.xpm", "tile_T.xpm", "tile_TB.xpm", "tile_TBL.xpm",
		"tile_TBR.xpm", "tile_TL.xpm", "tile_TR.xpm", "tile_TRL.xpm",};

	game->all_images.all_little_players = ft_calloc(sizeof(t_img_data), LPLAYER_NUMBER);
	if (!game->all_images.all_little_players)
		return (9);
	i = 0;
	while (i < LPLAYER_NUMBER)
	{
		make_name_player(name, all_name[i], LPLAYER_PATH, LPLAYER_PATH_SIZE);
		err = init_xpm_image(game, &game->all_images.all_little_players[i], name);
		if (err)
			return (free_img_array(game, &game->all_images.all_little_players, i), err);
		i++;
	}
	return (0);
}

int	init_all_big_player(t_game *game)
{
	int			err;
	char		name[BPLAYER_PATH_SIZE + BPLAYER_MAX_NAME_SIZE];
	int			i;
	const char	*all_name[] = {
		"tile_TBRL.xpm", "tile_NONE.xpm", "tile_B.xpm", "tile_BL.xpm",
		"tile_BLR.xpm", "tile_BR.xpm", "tile_L.xpm", "tile_R.xpm",
		"tile_RL.xpm", "tile_T.xpm", "tile_TB.xpm", "tile_TBL.xpm",
		"tile_TBR.xpm", "tile_TL.xpm", "tile_TR.xpm", "tile_TRL.xpm",};

	game->all_images.all_big_players = ft_calloc(sizeof(t_img_data), BPLAYER_NUMBER);
	if (!game->all_images.all_big_players)
		return (9);
	i = 0;
	while (i < BPLAYER_NUMBER)
	{
		make_name_player(name, all_name[i], BPLAYER_PATH, BPLAYER_PATH_SIZE);
		err = init_xpm_image(game, &game->all_images.all_big_players[i], name);
		if (err)
			return (free_img_array(game, &game->all_images.all_big_players, i), err);
		i++;
	}
	return (0);
}

int	init_player(t_game *game)
{
	game->player.all_player_img = 0;
	game->player.anim_duration = 0;
	game->player.anim_start = 0;
	game->player.anim_length = 1;
	game->player.img_player = game->all_images.all_little_players[0];
	game->player.height = game->player.img_player.height;
	game->player.width = game->player.img_player.width;
	game->x_position = game->start.game_x;
	game->player.x_pos = game->start.player_x;
	game->player.y_pos = game->start.player_y;
	game->player.top = false;
	game->player.bottom = false;
	game->player.right = false;
	game->player.left = false;
	game->player.y_speed = 0.0;
	game->player.y_acceleration = 0.0;
	game->player.coins = 0;
	game->player.state = IDLE;
	return (0);
}