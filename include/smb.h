/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/08 14:51:32 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_H
# define SMB_H

# include "smb_struct.h"

# include <X11/X.h>

/*smb_init_object.c*/
t_dict			*get_dict_new(char *tag, t_object *object);
t_object		*obj_new(char *tag, float x, float y);

/*smb_parsing.c*/
t_dict			*get_all_object(int fd);
int				set_map(t_map *map, char *filename);
int				check_map_format(char *filename);
int				parsing(int argc, char **argv, t_map *map);

/*smb_event.c*/
int				key_released(KeySym keycode, t_game *game);
int				key_pressed(KeySym keycode, t_game *game);
int				close_request(t_game *game);

/*smb_put_player_to_img.c*/
void			put_player_to_image(t_game *game,
					t_player *player, t_img_data *img);

/*smb_put_map_to_image.c*/
void			put_map_to_image(t_game *game, char **map, int position);

/*smb_put_background_to_img.c*/
void			put_bg_to_image(t_game *game, int position, t_img_data *img);

/*smb_display.c*/
unsigned int	get_pxl_color(t_img_data img, int x, int y);
int				display(t_game *game);

/*smb_collisions.c*/
int				check_collisions_bottom(t_game *game, float x_pos,
					float y_pos, float position);
int				check_collisions(t_game *game, float x_pos,
					float y_pos, float position);

/*smb_move*.c*/
int				move_right(t_game *game, t_player *player);
int				move_left(t_game *game, t_player *player);
int				apply_gravity(t_game *game, t_player *player);

/*smb_update.c*/
int				update(t_game *game);

/*smb_game_loop.c*/
int				game_loop(t_game *game);

/*smb_init_tiles.c*/
int				init_all_tiles(t_game *game);

/*smb_init_image.c*/
int				init_image(t_game *game, int width,
					int height, t_img_data *img);
int				init_xpm_image(t_game *game, t_img_data *img, char *name);

/*smb_init_game.c*/
int				init_game(t_game *game);

/*smb_free_init.c*/
void			window_fail(t_game *game);
void			background_fail(t_game *game);
void			map_image_fail(t_game *game);
void			all_image_fail(t_game *game);

/*smb_free.c*/
void			free_img_array(t_game *game, t_img_data *imgs, int number);
void			free_all_image(t_game *game);
void			free_game(t_game *game);

/*smb_error.c*/
void			smb_print_error(int code);

/*smb_wall_constructor.c*/
void			convert_plateformer_map(char **map, int x, int y, int max_y);
void			convert_outdoor_map(char **map, int x, int y, int max_y);
void			convert_indoor_map(char **map, int x, int y, int max_y);
void			wall_constructor(char **map, int max_y,
					void (*convert_function)(char **, int, int, int));
#endif