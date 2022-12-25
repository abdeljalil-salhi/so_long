/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:33:20 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/25 16:50:22 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

struct s_ne
{
	int	width;
	int	height;
};

int	ft_new_enemy(t_game *g, int row, int column, int type)
{
	void		*img;
	int			frame;
	int			deg;
	t_enemies	enemy;
	struct s_ne	s;

	enemy = ft_find_enemy(g, row, column);
	frame = g->sprites.enemy.frame;
	deg = enemy.deg;
	img = mlx_xpm_file_to_image(g->mlx, g->sprites.enemy.path[type][deg][frame],
			&s.width, &s.height);
	if (!img)
		return (ft_error(g, "Failed to load enemy xpm."));
	if (type == 0)
		mlx_put_image_to_window(g->mlx, g->win.ref, img,
			column * PX, row * PX - 32);
	else if (type == 1)
		mlx_put_image_to_window(g->mlx, g->win.ref, img,
			column * PX - 11, row * PX - 18);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_border(t_game *g, int row, int column, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(g->mlx, path, &width, &height);
	if (!img)
		return (ft_error(g, "Failed to load border xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * NPX, row * NPX);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_centered(t_game *g, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(g->mlx, path, &width, &height);
	if (!img)
		return (ft_error(g, "Failed to load centered xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		(g->win.width * PX + NPX) / 2 - width / 2,
		(g->win.height * PX + NPX) / 2 - height / 2);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_tip(t_game *g, int color)
{
	t_coords	pos;

	pos.r = g->win.height * PX + NPX / 2;
	pos.c = NPX;
	mlx_string_put(g->mlx, g->win.ref, pos.c, pos.r, color,
		g->tip.message);
	return (0);
}
