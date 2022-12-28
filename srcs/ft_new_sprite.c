/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:41:42 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 19:34:00 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_new_wall(t_game *g, int row, int column)
{
	void	*img;
	int		frame;
	int		width;
	int		height;

	frame = g->sprites.wall.frame;
	img = mlx_xpm_file_to_image(g->mlx, g->sprites.wall.path[frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load wall xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * PX + PX, row * PX + PX);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_ground(t_game *g, int row, int column)
{
	void	*img;
	int		frame;
	int		width;
	int		height;

	frame = g->sprites.ground.frame;
	img = mlx_xpm_file_to_image(g->mlx, g->sprites.ground.path[frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load ground xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * PX + PX, row * PX + PX + 12);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_player(t_game *g, int row, int column)
{
	void	*img;
	int		frame;
	int		deg;
	int		width;
	int		height;

	deg = g->sprites.player.deg;
	frame = g->sprites.player.frame;
	img = mlx_xpm_file_to_image(g->mlx, g->sprites.player.path[deg][frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load player xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * PX + PX, row * PX + PX);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_exit(t_game *g, int row, int column)
{
	void	*img;
	int		frame;
	int		width;
	int		height;

	frame = g->sprites.exit.frame;
	img = mlx_xpm_file_to_image(g->mlx, g->sprites.exit.path[frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load exit xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * PX + PX, row * PX + PX + 12);
	mlx_destroy_image(g->mlx, img);
	return (0);
}

int	ft_new_collectible(t_game *g, int row, int column)
{
	void		*img;
	int			frame;
	int			width;
	int			height;
	t_collecs	collectible;

	collectible = ft_find_collectible(g, row, column);
	frame = collectible.type;
	img = mlx_xpm_file_to_image(g->mlx, g->sprites.collec.path[frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load collectible xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * PX + PX + 4, row * PX + PX + 8 + g->sprites.collec.y);
	mlx_destroy_image(g->mlx, img);
	return (0);
}
