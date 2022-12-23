/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:33:20 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/23 23:34:23 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_enemies	ft_find_enemy(t_game *g, int r, int c)
{
	int			i;
	t_enemies	empty;

	ft_bzero(&empty, sizeof(t_enemies));
	i = -1;
	while (++i < g->n_enemies)
		if (g->enemies[i].pos.r == r && g->enemies[i].pos.c == c)
			return (g->enemies[i]);
	return (empty);
}

int	ft_new_enemy(t_game *g, int row, int column, int type)
{
	void		*img;
	int			frame;
	int			deg;
	int			width;
	int			height;
	t_enemies	enemy;

	enemy = ft_find_enemy(g, row, column);
	frame = g->sprites.enemy.frame;
	deg = enemy.deg;
	img = mlx_xpm_file_to_image(g->mlx, g->sprites.enemy.path[type][deg][frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load enemy xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * PX, row * PX - 32);
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
