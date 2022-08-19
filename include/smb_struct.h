/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/19 14:35:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_STRUCT_H
# define SMB_STRUCT_H

# include "dict.h"

# include <X11/X.h>
# include <stdbool.h>
# include <X11/keysym.h>

typedef struct s_game	t_game;
typedef KeySym			t_key;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img_data;

typedef struct s_hbox
{
	int	x_max;
	int	y_max;
	int	x_min;
	int	y_min;
	int	direction;
}	t_hbox;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_collisions
{
	int	x;
	int	y;
	int	height;
	int	width;
	int	direction;
}	t_collisions;

typedef struct s_object
{
	t_img_data		*all_img;
	t_img_data		*img;
	float			x;
	float			y;
	int				width;
	int				height;
	bool			is_strong;
	bool			is_collide;
	bool			is_visible;
	int				start_frame;
	int				nb_image;
	int				animation_duration;
	int				col_count;
	float			y_speed;
	float			y_acceleration;
	float			x_speed;
	t_collisions	col_object;
	int				(*col_fonction)(t_game *game, t_dict *elem,
			struct s_object *obj, int direction);
	int				(*update_fonction)(t_game *game, t_dict *elem,
			struct s_object *obj);
	int				(*del_fonction)(t_game *game, t_dict *elem,
			struct s_object *obj);
}	t_object;

typedef struct s_map
{
	char		**map_data;
	int			width;
	int			height;
	t_dict		*all_object;
	long		start_time;
	long		time;
}	t_map;

typedef struct s_all_images
{
	t_img_data	*all_tiles;
	t_img_data	*all_coins;
	t_img_data	*all_lplyrs;
	t_img_data	*all_bplyrs;
	t_img_data	*all_fplyrs;
	t_img_data	*all_fireballs;
	t_img_data	*all_goombas;
	t_img_data	*all_piranhas;
	t_img_data	*all_characters;
	t_img_data	sign;
	t_img_data	big_tree;
	t_img_data	block;
	t_img_data	end_bar;
	t_img_data	flag;
	t_img_data	castle;
	t_img_data	fire_flower;
	t_img_data	red_champi;
	t_img_data	loot_block;
	t_img_data	loot_block_use;
	t_img_data	breakable_block;
}	t_all_images;

typedef struct s_player
{
	t_img_data	*all_player_img;
	t_img_data	img_player;
	int			anim_frame_start;
	int			anim_start;
	int			anim_length;
	int			anim_duration;
	float		x_pos;
	float		y_pos;
	int			width;
	int			height;
	int			left;
	int			right;
	bool		top;
	bool		bottom;
	float		x_speed;
	float		x_acceleration;
	float		x_max_speed;
	float		y_speed;
	float		y_acceleration;
	int			coins;
	int			state;
	int			orientation;
	int			evolution;
	int			end_score;
	int			time_score;
	int			coin_score;
	int			final_score;
	int			invincible_frame;
	int			fireball_frame;
}	t_player;

typedef struct s_start
{
	int	player_x;
	int	player_y;
	int	game_x;
}	t_start;

typedef struct s_mlx
{
	void		*display;
	void		*window;
}	t_mlx;

typedef struct s_game
{
	t_mlx			mlx;
	t_img_data		background;
	t_img_data		window_image;
	t_map			map;
	t_all_images	all_images;
	t_player		player;
	t_collisions	collide_obj;
	t_start			start;
	long			last_time_frame;
	long			delay;
	float			x_position;
	long int		current_frame;
	int				(*update_fct)(struct s_game *game);
	int				(*display_fct)(struct s_game *game);
	int				(*keypressed_fct)(t_key key, struct s_game *game);
	int				(*keyreleased_fct)(t_key key, struct s_game *game);
}	t_game;

#endif
