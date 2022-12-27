/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_sprite_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:19:54 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 12:00:00 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_new_attack(t_game *g, int row, int column, int frame)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(g->mlx, g->sprites.attack.path[frame],
			&width, &height);
	if (!img)
		return (ft_error(g, "Failed to load attack xpm."));
	mlx_put_image_to_window(g->mlx, g->win.ref, img,
		column * PX, row * PX);
	mlx_destroy_image(g->mlx, img);
	return (0);
}
