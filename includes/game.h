/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramedjra <ramedjra@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:18:14 by ramedjra          #+#    #+#             */
/*   Updated: 2023/04/19 13:18:20 by ramedjra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# ifndef __APPLE__
#  include "../mlx/mlx.h"
# elif __LINUX__
#  include "../mlx_linux/mlx.h"
# endif

# define SS 32
# define WALL "./sprites/Other/Walls/wall.xpm"
# define EMPTY "./sprites/Other/Walls/black.xpm"
# define COLLECTIBLE "./sprites/Other/Pacdots/pacdot_food.xpm"
# define PLAYER_RIGHT "./sprites/Pac-Man/pac_open_right.xpm"
# define PLAYER_LEFT "./sprites/Pac-Man/pac_open_left.xpm"
# define PLAYER_UP "./sprites/Pac-Man/pac_open_up.xpm"
# define PLAYER_DOWN "./sprites/Pac-Man/pac_open_down.xpm"
# define PLAYER_CLOSED "./sprites/Pac-Man/pac_closed.xpm"
# define PLAYER "./sprites/Pac-Man/pac_open_right.xpm"
# define ENEMY_LEFT "./sprites/Ghosts/B/ghost_left1"
# define ENEMY_RIGHT "./sprites/Ghosts/B/ghost_right1"
# define EXIT "./sprites/Other/Portal/portal.xpm"

typedef struct s_map
{
	int		fd;
	char	**matrix;
	char	*line;
	void	*img_ptr;
	int		img_width;
	int		img_height;
	int		width;
	int		height;
	int		counter;
	int		x;
	int		y;
	int		coins;
	int		coins_counter;
	int		exits;
	void	*wall_img;
	void	*empty_img;
	void	*c_img;
	void	*exit_img;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		score;
	int		count;
	void	*img;
	int		width;
	int		height;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		go_up;
	int		go_down;
	int		go_left;
	int		go_right;
	void	*img_up;
	void	*img_down;
	void	*img_left;
	void	*img_right;
	void	*img_closed;
	t_list	sprites;
}	t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		mov_up;
	int		mov_down;
	int		mov_left;
	int		mov_right;
	void	*img;
	int		count;
	int		dir;
	t_list	sprites;
}	t_enemy;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_player	*player;
	t_enemy		*enemy;
	int			moves;
}	t_game;

//image.c
void	init_img(t_game *game);

//so_long.c
int		update(t_game *game);
void	init_game(t_game *game);
//map.c
int		init_map(t_game *game, char *map_path);
void	draw_map(t_game *g);
int		get_map_size(char *map_path, t_game *game);
int		create_matrix(char *map_path, t_game *game);

void	draw_xpm(t_game **game, void *img, int x, int y);

// player.c
void	init_player(t_game *game);
void	get_players_cords(t_game *game);
int		move_player(int keynum, t_game *game);
void	check_legal(t_game *game);

// move.c
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

// check_2.c
void	check_chars(t_game *game);
void	sanity_checks(t_game *game);

// misc.c
void	draw_score(t_game *game);
int		check_exit(t_game *game);
int		check_move(char **matrix, int x, int y);
void	exit_game(t_game *game, char *msg, int status);

//check 
void	check_path(char *s);
void	check_map(t_game *game);

//enemy.c
void	init_enemy(t_game *game);
void	get_enemy_cords(t_game *game);
void	move_enemy(t_game *game);

//anim.c
void	animate_enemy(t_game *game, int dir);

// utilis.c
void	ft_free_arr(char **str);
size_t	ft_arrlen(char **arr);
char	**ft_arrdup(char **arr);

#endif
