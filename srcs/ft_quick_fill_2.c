/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_fill_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 06:47:20 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 11:49:49 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_enemies_path(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < g->win.width)
		{
			if (g->map.arr[i][j] == 5)
				if (g->map.arr[i][j - 1] != 0 && g->map.arr[i][j + 1] != 0)
					return (ft_error(g, "Horizontal enemy blocking the way."));
			if (g->map.arr[i][j] == 6)
				if (g->map.arr[i - 1][j] != 0 && g->map.arr[i + 1][j] != 0)
					return (ft_error(g, "Vertical enemy blocking the way."));
		}
	}
	return (0);
}
