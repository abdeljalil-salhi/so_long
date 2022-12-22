/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:33:20 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/21 21:29:11 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_new_enemy(t_game *g, int row, int column, int type)
{
	void	*img;
	int		frame;
	int		deg;
	int		width;
	int		height;

	frame = g->sprites.enemy.frame;
	deg = type + 1;
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
