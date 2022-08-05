/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 23:52:38 by lgiband          ###   ########.fr       */
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
	t_dict *object;
	int		x;
	int		y;
}	t_object;

typedef struct s_map
{
	char		**map_data;
	t_object	*object_data;
	t_img_data	*map_img;
}	t_map;

typedef struct	s_all_images
{
	t_img_data	*all_tiles;
}	t_all_images;

typedef struct s_game
{
	t_mlx			mlx;
	t_img_data		background;
	t_img_data		window_image;
	t_map			map;
	t_all_images	all_images;
	float			x_position;
	bool			refresh;
}	t_game;

#endif