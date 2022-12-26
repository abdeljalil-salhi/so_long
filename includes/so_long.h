/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:55:11 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/26 13:18:58 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <time.h>
# include <mlx.h>
# include <signal.h>

# define FPS 30
# define NPX 32
# define PX 32 + 32
# define COLOR 0x00FF0000
# define COLLEC_TYPES 7
# define ESC_MESSAGE "Press [ESC] to quit..."
# define P_MESSAGE "Press [P] to resume..."
# define TMP "/tmp/.gameover"

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
	char		*path[5][2];
	t_coords	pos;
	int			frame;
	int			standing;
	int			energy;
	int			dying;
	int			dead;
	int			deg;
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
	int		next;
	int		y;
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

typedef struct s_sounds
{
	char	*soundtrack;
	char	*collected;
	char	*won;
	char	*lost;
}	t_sounds;

typedef struct s_collecs
{
	int			id;
	int			type;
	t_coords	pos;
	int			init;
}	t_collecs;

typedef struct s_enemies
{
	int			id;
	int			type;
	t_coords	pos;
	int			deg;
	int			dead;
	int			next;
}	t_enemies;

typedef struct s_tip
{
	char	*message;
	int		display;
}	t_tip;

typedef struct s_alloc
{
	int	map;
	int	collectibles;
	int	enemies;
}	t_alloc;

typedef struct s_pid
{
	pid_t	sound_track;
	pid_t	sound_effect;
	int		effect_playing;
}	t_pid;

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	t_map		map;
	char		*exit_message;
	t_sprites	sprites;
	t_sounds	sounds;
	int			n_collectibles;
	t_collecs	*collectibles;
	int			n_enemies;
	t_enemies	*enemies;
	int			paused;
	int			game_over;
	int			won;
	int			moves;
	t_tip		tip;
	t_alloc		allocated;
	t_pid		pid;
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
	KEY_P = 35,
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126
};

int			ft_check_and_init(t_game *g, char *map);
int			ft_check_extension(t_game *g);
int			ft_read_file(t_game *g);
int			ft_init_map(t_game *g);
int			ft_check_map(t_game *g);
int			ft_check_borders(t_game *g);
int			ft_check_uniqueness(t_game *g);
int			ft_set_ceil_type(t_game *g, char c);
int			ft_player_pos(t_game *g);
int			ft_fill_enemy(t_game *g, t_coords p, int type, int *id);
int			ft_launch_enemies(t_game *g);
int			ft_fill_collectible(t_game *g, t_coords p, int *id);
int			ft_launch_collectibles(t_game *g);
int			ft_move_enemies(t_game *g);
int			ft_animate_enemies(t_game *g);
int			ft_animate_collectibles(t_game *g);

int			ft_init_player(t_game *g);
int			ft_init_exit(t_game *g);
int			ft_init_collectibles(t_game *g);
int			ft_init_wall(t_game *g);
int			ft_init_ground(t_game *g);
int			ft_init_enemy(t_game *g);
int			ft_init_border(t_game *g);
int			ft_new_wall(t_game *g, int row, int column);
int			ft_new_ground(t_game *g, int row, int column);
int			ft_new_player(t_game *g, int row, int column);
int			ft_new_exit(t_game *g, int row, int column);
int			ft_new_collectible(t_game *g, int row, int column);
int			ft_new_enemy(t_game *g, int row, int column, int type);
int			ft_new_border(t_game *g, int row, int column, char *path);
int			ft_new_centered(t_game *g, char *path);
int			ft_new_tip(t_game *g, int color);
int			ft_check_components(t_game *g, int frame);
int			ft_draw_upper_layer(t_game *g);
int			ft_render(t_game *g);
int			ft_draw_borders(t_game *g);
int			ft_draw(t_game *g);

void		ft_exit_error(t_game *g, char *str);
int			ft_error(t_game *g, char *str);
void		ft_stop_sound_track(t_game *g);
void		ft_game_paused(t_game *g);
void		ft_game_over(t_game *g);
int			ft_free_exit(t_game *g);

int			ft_count_occurences(char *str, char c);
int			ft_free_tab(void **tab);
int			ft_free_double_int(int **tab, size_t size);
int			ft_free(void *ptr);
int			ft_close(int fd);

int			ft_move_player_left(t_game *g);
int			ft_move_player_right(t_game *g);
int			ft_move_player_up(t_game *g);
int			ft_move_player_down(t_game *g);

int			ft_afplay(t_game *g, char *path);
int			ft_init_sounds(t_game *g);
void		ft_play_sound_track(t_game *g);
void		ft_play_sound_effect(t_game *g, char *sound);

t_enemies	ft_find_enemy(t_game *g, int r, int c);
t_collecs	ft_find_collectible(t_game *g, int r, int c);

#endif
