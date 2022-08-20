/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:03:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/20 15:57:44 by lgiband          ###   ########.fr       */
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

/*Player state*/
# define IDLE 0
# define RUN 1
# define UJUMP 2
# define DJUMP 3
# define CROUCH 4
# define DEAD 5
# define SLIDE 6
# define BAR 7
# define GROWTH 8
# define SHRINK 9
# define VICTORY 10
# define C_SHRINK 11
# define C_GROWTH 12

/*Player orientation*/
# define O_LEFT 0
# define O_RIGHT 1

/*Player evolution*/
# define LITTLE 0
# define BIG 1
# define FIRE 2

/*PLayer image in one direction*/
# define O_LITTLE 10
# define O_BIG 14
# define O_FIRE 11

/*Moving Speed*/
# define PLAYER_SPEED 0.1875f
# define BG_PARALLAX_FACTOR 0.5f

/*120fps=0.5f, 30fps=0.58f, 60fps=0.54f, 240fps=0.5f*/
/*8delay:0.5f, */
/*Start base speed for jump*/
# define JUMP_SPEED 0.5f
# define REJUMP_SPEED 0.5f
# define JUMP_SPEED_END 0.4f

# define V_DOWN_MAX -0.3f

# define V_HOR_MAX 0.1875f
# define V_END_MAX 0.0625f
# define V_ENDJUMP_MAX 0.1250f

# define ACCEL_HOR 0.000015f
# define DECCEL_HOR 0.000015f

/*Gravity power*/
# define GRAVITY_UP 0.00003f
# define GRAVITY_DOWN 0.00003f

# define END_BAR_GRAVITY 0.125f

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

/*Path to the directory of tiles images*/
# define LPLAYER_PATH "files/xpm/player/little/"
/*Size of the path*/
# define LPLAYER_PATH_SIZE 25
/*Size max of the player name*/
# define LPLAYER_MAX_NAME_SIZE 24
/*Number of different little player*/
# define LPLAYER_NUMBER 23

/*Path to the directory of tiles images*/
# define BPLAYER_PATH "files/xpm/player/big/"
/*Size of the path*/
# define BPLAYER_PATH_SIZE 22
/*Size max of the player name*/
# define BPLAYER_MAX_NAME_SIZE 24
/*Number of different big player*/
# define BPLAYER_NUMBER 29

/*Path to the directory of tiles images*/
# define FPLAYER_PATH "files/xpm/player/fire/"
/*Size of the path*/
# define FPLAYER_PATH_SIZE 23
/*Size max of the player name*/
# define FPLAYER_MAX_NAME_SIZE 24
/*Number of different fire player*/
# define FPLAYER_NUMBER 23

/*Player animation speed*/
# define PLAYER_RUN_ANIM_SPEED 200
# define PLAYER_GROWTH_ANIM_SPEED 1000
# define PLAYER_VICTORY_ANIM_DURATION 800
# define PLAYER_DEAD_ANIM_DURATION 200

# define START_DEAD_SPEED 0.38f
# define MAX_DEAD_SPEED 0.25f

# define PLAYER_INVINCIBLE_DURATION 800

/*direction*/
# define NONE 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define UP 4

/*Max long*/
# define MAX_LONG 9223372036854775807

/*Multiplier of the score when the player grab the flag bar*/
# define MAX_SCORE 7000
# define SCORE_MULTIPLIER 20
# define COIN_MULTIPLIER 45
# define TIME_MULTIPLIER 1

#endif