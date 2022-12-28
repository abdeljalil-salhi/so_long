/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:19:54 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 19:29:49 by absalhi          ###   ########.fr       */
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
