/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:55:11 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/23 21:49:33 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

# define FPS 30
# define NPX 32
# define PX 32 + 32

typedef struct s_coords
{
	int	r;
	int	c;
}	t_coords;

typedef struct s_window
{
	void	*ref;
	int		width;
	int		height;
}	t_window;

typedef struct s_image
{
	void		*ref;
	int			width;
	int			height;
	char		*addr;
	int			bpp;
	int			length;
	int			endian;
}	t_image;

typedef struct s_file
{
	char	*name;
	int		fd;
}	t_file;

typedef struct s_map
{
	t_file	file;
	int		**arr;
}	t_map;

typedef struct s_player
{
	char	*path[5][2];
	int		r;
	int		c;
	int		frame;
	int		standing;
	int		energy;
	int		dying;
	int		dead;
	int		deg;
}	t_player;

typedef struct s_exit
{
	char	*path[6];
	int		frame;
	int		closed;
	int		opening;
	int		open;
}	t_exit;

typedef struct s_collec
{
	char	*path[7];
	int		frame;
}	t_collec;

typedef struct s_wall
{
	char	*path[3];
	int		frame;
}	t_wall;

typedef struct s_ground
{
	char	*path[3];
	int		frame;
}	t_ground;

typedef struct s_enemy
{
	char	*path[2][4][4];
	int		frame;
}	t_enemy;

typedef struct s_sprites
{
	t_player	player;
	t_exit		exit;
	t_collec	collec;
	t_wall		wall;
	t_ground	ground;
	t_enemy		enemy;
	char		*border[4];
}	t_sprites;

typedef struct s_enemies
{
	int			id;
	int			type;
	t_coords	pos;
	int			deg;
	int			dead;
	int			next;
}	t_enemies;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	t_map		map;
	char		*exit_message;
	t_sprites	sprites;
	int			collectibles;
	int			n_enemies;
	t_enemies	*enemies; // h = 5 (broly), v = 6
	int			paused;
	int			moves;
}	t_game;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	KEY_A = 0,
	KEY_D = 2,
	KEY_S = 1,
	KEY_W = 13,
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126
};

int		ft_check_and_init(t_game *g, char *map);
int		ft_check_extension(t_game *g);
int		ft_read_file(t_game *g);
int		ft_init_map(t_game *g);
int		ft_check_map(t_game *g);
int		ft_check_borders(t_game *g);
int		ft_check_uniqueness(t_game *g);
int		ft_set_ceil_type(t_game *g, char c);
int		ft_player_pos(t_game *g);
int		ft_launch_enemies(t_game *g);
int		ft_move_enemies(t_game *g);
int		ft_animate_enemies(t_game *g);

int		ft_init_player(t_game *g);
int		ft_init_exit(t_game *g);
int		ft_init_collectibles(t_game *g);
int		ft_init_wall(t_game *g);
int		ft_init_ground(t_game *g);
int		ft_init_enemy(t_game *g);
int		ft_init_border(t_game *g);
int		ft_new_wall(t_game *g, int row, int column);
int		ft_new_ground(t_game *g, int row, int column);
int		ft_new_player(t_game *g, int row, int column);
int		ft_new_exit(t_game *g, int row, int column);
int		ft_new_collectible(t_game *g, int row, int column);
int		ft_new_enemy(t_game *g, int row, int column, int type);
int		ft_new_border(t_game *g, int row, int column, char *path);
int		ft_render(t_game *g);
int		ft_draw(t_game *g);

void	ft_exit_error(char *str);
int		ft_error(t_game *g, char *str);
int		ft_game_over(t_game *g);

int		ft_count_occurences(char *str, char c);
int		ft_free_tab(void **tab);
int		ft_free_double_int(int **tab, size_t size);
int		ft_free(void *ptr);
int		ft_close(int fd);

int		ft_move_player_left(t_game *g);
int		ft_move_player_right(t_game *g);
int		ft_move_player_up(t_game *g);
int		ft_move_player_down(t_game *g);

#endif
