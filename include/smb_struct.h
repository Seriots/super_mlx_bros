/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/06 19:35:31 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_STRUCT_H
# define SMB_STRUCT_H

# include "dict.h"

# include <stdbool.h>

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

typedef struct s_object
{
	t_img_data	*img;
	float		x;
	float		y;
	int		width;
	int		height;
	bool		is_collide;
	int		start_frame;
	int		nb_image;
	int		animation_duration;
	//fonction associe a la collision
}	t_object;

typedef struct s_map
{
	char		**map_data;
	int			width;
	int			height;
	t_object	*object_data;
	t_img_data	*map_img;
}	t_map;

typedef struct	s_all_images
{
	t_img_data	*all_tiles;
}	t_all_images;

typedef struct	s_player
{
	t_img_data	*all_player_img;
	t_img_data	img_player;
	float		x_pos;
	float		y_pos;
	int			width;
	int			height;
	bool		left;
	bool		right;
	bool		top;
	bool		bottom;
	int			jump_speed;
}	t_player;

typedef struct s_game
{
	t_mlx			mlx;
	t_img_data		background;
	t_img_data		window_image;
	t_map			map;
	t_all_images	all_images;
	t_player		player;
	float			x_position;
	int			current_frame; 
}	t_game;

#endif
