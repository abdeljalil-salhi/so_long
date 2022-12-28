/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_fill_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 06:47:20 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 19:39:42 by absalhi          ###   ########.fr       */
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

int	ft_quickfill_condition_left(t_game *g, t_coords p)
{
	return (p.c - 1 > 0 && (g->quickfill.dc[p.r][p.c - 1] == 0
		|| g->quickfill.dc[p.r][p.c - 1] == 3
		|| g->quickfill.dc[p.r][p.c - 1] == 4
		|| g->quickfill.dc[p.r][p.c - 1] == 5
		|| g->quickfill.dc[p.r][p.c - 1] == 6));
}

int	ft_quickfill_condition_right(t_game *g, t_coords p)
{
	return (p.c + 1 < g->win.width && (g->quickfill.dc[p.r][p.c + 1] == 0
		|| g->quickfill.dc[p.r][p.c + 1] == 3
		|| g->quickfill.dc[p.r][p.c + 1] == 4
		|| g->quickfill.dc[p.r][p.c + 1] == 5
		|| g->quickfill.dc[p.r][p.c + 1] == 6));
}

int	ft_quickfill_condition_up(t_game *g, t_coords p)
{
	return (p.r - 1 > 0 && (g->quickfill.dc[p.r - 1][p.c] == 0
		|| g->quickfill.dc[p.r - 1][p.c] == 3
		|| g->quickfill.dc[p.r - 1][p.c] == 4
		|| g->quickfill.dc[p.r - 1][p.c] == 5
		|| g->quickfill.dc[p.r - 1][p.c] == 6));
}

int	ft_quickfill_condition_down(t_game *g, t_coords p)
{
	return (p.r + 1 < g->win.height && (g->quickfill.dc[p.r + 1][p.c] == 0
		|| g->quickfill.dc[p.r + 1][p.c] == 3
		|| g->quickfill.dc[p.r + 1][p.c] == 4
		|| g->quickfill.dc[p.r + 1][p.c] == 5
		|| g->quickfill.dc[p.r + 1][p.c] == 6));
}
