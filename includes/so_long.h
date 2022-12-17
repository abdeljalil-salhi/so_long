/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:55:11 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/17 06:36:23 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

typedef struct s_coords
{
	int	x;
	int	y;
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
	t_coords	coords;
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

typedef struct s_game
{
	void		*mlx;
	t_window	win;
	t_map		map;
	char		*exit_message;
}	t_game;

int		ft_check_and_init(t_game *g, char *map);
int		ft_check_extension(t_game *g);
int		ft_read_file(t_game *g);
int		ft_init_map(t_game *g);
int		ft_check_map(t_game *g);
int		ft_check_borders(t_game *g);
int		ft_check_uniqueness(t_game *g);
int		ft_set_ceil_type(t_game *g, char c);

void	ft_exit_error(char *str);
int		ft_error(t_game *g, char *str);

int		ft_count_occurences(char *str, char c);
int		ft_free_tab(void **tab);
int		ft_free(void *ptr);
int		ft_close(int fd);

#endif
