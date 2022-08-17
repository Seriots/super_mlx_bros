/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:10:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/17 05:04:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

#include "mlx.h"

#include "smb_struct.h"
#include "smb_settings.h"
#include "smb.h"

static void	make_name_player(char *all_path, const char *name,
	char *path, int size_path)
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
		"lm_idle_l.xpm", "lm_run_l.xpm", "lm_ujump_l.xpm", "lm_djump_l.xpm",
		"lm_crouch_l.xpm", "lm_slide_l.xpm", "lm_bar_l.xpm", 
		"lm_growth_l1.xpm", "lm_growth_l2.xpm", "lm_growth_l3.xpm","lm_idle_r.xpm",
		"lm_run_r.xpm", "lm_ujump_r.xpm", "lm_djump_r.xpm", "lm_crouch_r.xpm","lm_slide_r.xpm", "lm_bar_r.xpm", 
		"lm_growth_r1.xpm", "lm_growth_r2.xpm", "lm_growth_r3.xpm","lm_dead_l.xpm", "lm_dead_r.xpm"};

	game->all_images.all_little_players = ft_calloc(sizeof(t_img_data),
			LPLAYER_NUMBER);
	if (!game->all_images.all_little_players)
		return (9);
	i = 0;
	while (i < LPLAYER_NUMBER)
	{
		make_name_player(name, all_name[i], LPLAYER_PATH, LPLAYER_PATH_SIZE);
		err = init_xpm_image(game,
				&game->all_images.all_little_players[i], name);
		if (err)
			return (free_img_array(game,
					&game->all_images.all_little_players, i), err);
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
		"bm_idle_l.xpm", "bm_run_l1.xpm", "bm_run_l2.xpm", "bm_ujump_l.xpm",
		"bm_djump_l.xpm", "bm_crouch_l.xpm", "bm_slide_l.xpm", "bm_bar_l.xpm",
		"bm_growth_l1.xpm", "bm_growth_l2.xpm", "bm_growth_l3.xpm",
		"bm_idle_r.xpm", "bm_run_r1.xpm", "bm_run_r2.xpm", "bm_ujump_r.xpm",
		"bm_djump_r.xpm", "bm_crouch_r.xpm", "bm_slide_r.xpm", "bm_bar_r.xpm",
		"bm_growth_r1.xpm", "bm_growth_r2.xpm", "bm_growth_r3.xpm"};

	game->all_images.all_big_players = ft_calloc(sizeof(t_img_data),
			BPLAYER_NUMBER);
	if (!game->all_images.all_big_players)
		return (9);
	i = 0;
	while (i < BPLAYER_NUMBER)
	{
		make_name_player(name, all_name[i], BPLAYER_PATH, BPLAYER_PATH_SIZE);
		err = init_xpm_image(game, &game->all_images.all_big_players[i], name);
		if (err)
			return (free_img_array(game, &game->all_images.all_big_players, i),
				err);
		i++;
	}
	return (0);
}

int	init_player_next(t_game *game)
{
	game->player.y_speed = 0.0;
	game->player.y_acceleration = 0.0;
	game->player.x_speed = 0.0;
	game->player.x_acceleration = 0.0;
	game->player.x_max_speed = V_HOR_MAX;
	game->player.coins = 0;
	game->player.state = IDLE;
	game->player.orientation = O_RIGHT;
	game->player.evolution = LITTLE;
	game->player.end_score = 0;
	game->player.time_score = 0;
	game->player.coin_score = 0;
	game->player.final_score = 0;
	return (0);
}

int	init_player(t_game *game)
{
	game->player.all_player_img = game->all_images.all_little_players;
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
	return (init_player_next(game));
}
