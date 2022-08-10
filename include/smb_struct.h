/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 00:10:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_STRUCT_H
# define SMB_STRUCT_H

# include "dict.h"

# include <stdbool.h>
typedef struct s_game t_game;

typedef struct s_mlx
{
	void	*display;
	void	*window;
}	t_mlx;

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

typedef struct s_collisions
{
	int	x;
	int	y;
	int	height;
	int	width;
}	t_collisions;

typedef struct s_object
{
	t_img_data	*all_img;
	t_img_data	*img;
	float		x;
	float		y;
	int			width;
	int			height;
	bool		is_strong;
	bool		is_collide;
	bool		is_visible;
	int			start_frame;
	int			nb_image;
	int			animation_duration;
	int			(*col_fonction)(t_game *game, struct s_object *obj, int direction);
}	t_object;

typedef struct s_map
{
	char		**map_data;
	int			width;
	int			height;
	t_dict		*all_object;
}	t_map;

typedef struct s_all_images
{
	t_img_data	*all_tiles;
	t_img_data	*all_coins;
	t_img_data	sign;
}	t_all_images;

typedef struct s_player
{
	t_img_data	*all_player_img;
	t_img_data	img_player;
	float		x_pos;
	float		y_pos;
	int			width;
	int			height;
	int			left;
	int			right;
	bool		top;
	bool		bottom;
	float		y_speed;
	float		y_acceleration;
}	t_player;

typedef struct s_start
{
	int	player_x;
	int	player_y;
	int	game_x;
}	t_start;

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
	int				current_frame;
}	t_game;

#endif
