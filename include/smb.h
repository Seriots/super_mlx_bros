/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 22:46:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/05 21:03:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMB_H
# define SMB_H

# include "smb_struct.h"

# include <X11/X.h>

/*smb_parsing.c*/
int		set_map(t_map *map, char *filename);
int		check_map_format(char *filename);
int		parsing(int argc, char **argv, t_map *map);

/*smb_event.c*/
int		key_pressed(KeySym keycode, t_game *game);
int		close_request(t_game *game);

/*smb_display.c*/
int		display(t_game *game);

/*smb_init_image.c*/
int		init_image(t_game *game, int width, int height, t_img_data *img);
int		init_xpm_image(t_game *game, t_img_data *img, char *name);

/*smb_init_game.c*/
int		init_game(t_game *game);

/*smb_free.c*/
void	free_game(t_game *game);

/*smb_error.c*/
void	smb_print_error(int code);

/*smb_wall_constructor.c*/
void	convert_plateformer_map(char **map, int x, int y, int max_y);
void	convert_outdoor_map(char **map, int x, int y, int max_y);
void	convert_indoor_map(char **map, int x, int y, int max_y);
void	wall_constructor(char **map, int max_y,
					void (*convert_function)(char **, int, int, int));
#endif