/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:19:54 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 22:27:11 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_new_attack(t_game *g, int row, int column, int frame)
{
	void	*img;
	int		deg;
	int		width;
	int		height;

	deg = g->sprites.player.deg - 5;
	img = mlx_xpm_file_to_image(g->mlx, g->sprites.attack.path[deg][frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load attack xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * PX + PX, row * PX + PX);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_avatar(t_game *g)
{
	void	*img;
	int		frame;
	int		width;
	int		height;

	frame = g->sprites.player.saiyan;
	img = mlx_xpm_file_to_image(g->mlx, g->infos.avatar[frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load avatar xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		g->win.width * PX + PX - 200, 0);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_energy(t_game *g)
{
	void	*img;
	int		frame;
	int		width;
	int		height;

	frame = g->energy;
	if (frame > 3)
		frame = 3;
	img = mlx_xpm_file_to_image(g->mlx, g->infos.energy[frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load energy xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		g->win.width * PX + PX - 145, 10);
	mlx_destroy_image(g->mlx, img);
	return (0);
}
