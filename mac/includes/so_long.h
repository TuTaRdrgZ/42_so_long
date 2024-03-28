/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:07:34 by bautrodr          #+#    #+#             */
/*   Updated: 2023/12/20 17:34:19 by bautrodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RIGHT 1
# define LEFT 2
# define UP 3
# define DOWN 4

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../mlx/mlx_mac/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textures
{
	void		*floor;
	void		*coin;
	void		*closed_door;
	void		*opened_door;
	void		*wall;
}				t_textures;

typedef struct s_player
{
	void		*player_up;
	void		*player_down;
	void		*player_left;
	void		*player_right;
}				t_player;

typedef struct s_game
{
	void		*window;
	void		*mlx;
	int			width;
	int			height;
	int			moves;
	int			x;
	int			y;
	int			coins;
	int			flood_fill_coins;
	int			score;
	int			p_counter;
	int			e_counter;
	int			player_pos;
	int			map_col;
	int			map_rows;
	int			exit_x;
	int			exit_y;
	char		**map;
	t_textures	textures;
	t_player	player;
}				t_game;

int				destroy_program(t_game *game);
void			free_map(t_game *game);
void			free_visited(int **visited, t_game *game);
void			init_img(t_game *game);
void			add_graphics(t_game *game);
void			print_map(char *line, t_game *game, int index);
int				key_hook(int keycode, t_game *game);
void			print_error(t_game *game, int n);
void			print_player(t_game *game, int width, int heigth);
void			update_player_pos(t_game *game, int key);
void			flood_fill(t_game *game, int row, int col, int **visited);
int				valid_path(t_game *game, int i, int p_row, int p_col);
int				init_map(char *map, t_game *game, int linecount);
int				check_map(t_game *game, char *map);
int				more_checks(t_game *game, char *map);
int				check_filetype(char *str);
void			check_repeated(t_game *game, int i, int j);
void			print_map(char *line, t_game *game, int index);
int				same_length(t_game *game);

#endif
