/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_init_player_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:05:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 14:06:12 by lgiband          ###   ########.fr       */
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
		"lm_crouch_l.xpm", "lm_slide_l.xpm", "lm_bar_l.xpm", "lm_growth_l1.xpm",
		"lm_growth_l2.xpm", "lm_growth_l3.xpm", "lm_idle_r.xpm", "lm_run_r.xpm",
		"lm_ujump_r.xpm", "lm_djump_r.xpm", "lm_crouch_r.xpm", "lm_slide_r.xpm",
		"lm_bar_r.xpm", "lm_growth_r1.xpm", "lm_growth_r2.xpm",
		"lm_growth_r3.xpm", "lm_victory.xpm", "lm_dead_l.xpm", "lm_dead_r.xpm"};

	game->all_images.all_lplyrs = ft_calloc(sizeof(t_img_data),
			LPLAYER_NUMBER);
	if (!game->all_images.all_lplyrs)
		return (9);
	i = -1;
	while (++i < LPLAYER_NUMBER)
	{
		make_name_player(name, all_name[i], LPLAYER_PATH, LPLAYER_PATH_SIZE);
		err = init_xpm_image(game,
				&game->all_images.all_lplyrs[i], name);
		if (err)
			return (free_img_array(game, &game->all_images.all_lplyrs, i), err);
	}
	return (0);
}

static int	init_all_gib_player2(t_game *game, const char **all_name)
{
	int			err;
	char		name[BPLAYER_PATH_SIZE + BPLAYER_MAX_NAME_SIZE];
	int			i;

	game->all_images.all_bplyrs = ft_calloc(sizeof(t_img_data),
			BPLAYER_NUMBER);
	if (!game->all_images.all_bplyrs)
		return (9);
	i = -1;
	while (++i < BPLAYER_NUMBER)
	{
		make_name_player(name, all_name[i], BPLAYER_PATH, BPLAYER_PATH_SIZE);
		err = init_xpm_image(game, &game->all_images.all_bplyrs[i], name);
		if (err)
			return (free_img_array(game, &game->all_images.all_bplyrs, i), err);
	}
	return (0);
}

int	init_all_big_player(t_game *game)
{
	const char	*all_name[] = {
		"bm_idle_l.xpm", "bm_run_l1.xpm", "bm_run_l2.xpm", "bm_ujump_l.xpm",
		"bm_djump_l.xpm", "bm_crouch_l.xpm", "bm_slide_l.xpm", "bm_bar_l.xpm",
		"bm_shrink_l1.xpm", "bm_shrink_l2.xpm", "bm_shrink_l3.xpm",
		"bm_growth_l1.xpm", "bm_growth_l2.xpm", "bm_growth_l3.xpm",
		"bm_idle_r.xpm", "bm_run_r1.xpm", "bm_run_r2.xpm", "bm_ujump_r.xpm",
		"bm_djump_r.xpm", "bm_crouch_r.xpm", "bm_slide_r.xpm", "bm_bar_r.xpm",
		"bm_shrink_r1.xpm", "bm_shrink_r2.xpm", "bm_shrink_r3.xpm",
		"bm_growth_r1.xpm", "bm_growth_r2.xpm", "bm_growth_r3.xpm",
		"bm_victory.xpm"};

	return (init_all_gib_player2(game, all_name));
}

int	init_all_fire_player(t_game *game)
{
	int			err;
	char		name[FPLAYER_PATH_SIZE + FPLAYER_MAX_NAME_SIZE];
	int			i;
	const char	*all_name[] = {
		"fm_idle_l.xpm", "fm_run_l1.xpm", "fm_run_l2.xpm", "fm_ujump_l.xpm",
		"fm_djump_l.xpm", "fm_crouch_l.xpm", "fm_slide_l.xpm", "fm_bar_l.xpm",
		"fm_shrink_l1.xpm", "fm_shrink_l2.xpm", "fm_shrink_l3.xpm",
		"fm_idle_r.xpm", "fm_run_r1.xpm", "fm_run_r2.xpm", "fm_ujump_r.xpm",
		"fm_djump_r.xpm", "fm_crouch_r.xpm", "fm_slide_r.xpm", "fm_bar_r.xpm",
		"fm_shrink_r1.xpm", "fm_shrink_r2.xpm", "fm_shrink_r3.xpm",
		"fm_victory.xpm"};

	game->all_images.all_fplyrs = ft_calloc(sizeof(t_img_data),
			FPLAYER_NUMBER);
	if (!game->all_images.all_fplyrs)
		return (9);
	i = -1;
	while (++i < FPLAYER_NUMBER)
	{
		make_name_player(name, all_name[i], FPLAYER_PATH, FPLAYER_PATH_SIZE);
		err = init_xpm_image(game, &game->all_images.all_fplyrs[i], name);
		if (err)
			return (free_img_array(game, &game->all_images.all_fplyrs, i), err);
	}
	return (0);
}
