/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:03:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/11 20:07:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_SETTINGS_H
# define SMB_SETTINGS_H

/*Name of the game*/
# define GAME_NAME "Super Mlx Bros"

/*Name of the executable*/
# define EXE_NAME "super_mlx_bros"

/*Screen dimension*/
# define SCREEN_HEIGHT 544
# define SCREEN_WIDTH 960

/*fps du jeu bg*/
# define FPS 120

/*Path to the background file*/
# define BACKGROUND_NAME "files/xpm/background/Infinite_sky_background.xpm"

/*Moving Speed*/
# define PLAYER_SPEED 0.1875f
# define BG_PARALLAX_FACTOR 0.5f

/*120fps=0.5f, 30fps=0.58f, 60fps=0.54f, 240fps=0.5f*/
/*8delay:0.5f, */
/*Start base speed for jump*/
# define JUMP_SPEED 0.5f
# define REJUMP_SPEED 0.5f

# define V_DOWN_MAX -0.3f

/*Gravity power*/
# define GRAVITY_UP 0.00003f
# define GRAVITY_DOWN 0.00003f

/*SCREEN_HEIGHT / 16*/
# define MAP_HEIGHT_TILES 34
# define MAP_WIDTH_TILES 60
/*Value allowed in the map file*/
# define MAP_SET "01"
/*Extension allowed for map file*/
# define MAP_EXTENSION ".map"
# define MAP_EXTENSION_ERROR "/.map"

/*Path to the directory of tiles images*/
# define TILES_PATH "files/xpm/tiles/"
# define TILES_PATH_SIZE 17
# define TILES_MAX_NAME_SIZE 16
/*Number of different tiles*/
# define TILES_NUMBER 16
# define TILES_SIZE 16

/*direction*/
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

/*Max long*/
# define MAX_LONG 9223372036854775807

#endif