/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:06:16 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/26 15:28:20 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_deep_copy_map(t_game *g)
{
	int	i;
	int	j;

	g->quickfill.dc = (int **) ft_calloc(g->win.height, sizeof(int *));
	if (!g->quickfill.dc)
		return(ft_error(g, "ft_quick_fill.c: (int **) ft_calloc failed."));
	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		g->quickfill.dc[i] = (int *) ft_calloc(g->win.width, sizeof(int));
		if (!g->quickfill.dc[i])
			return(ft_free(g->quickfill.dc)
				+ ft_free_double_int(g->quickfill.dc, (size_t) i)
				+ ft_error(g, "ft_quick_fill.c: (int *) ft_calloc failed."));
		while (++j < g->win.width)
			g->quickfill.dc[i][j] = g->map.arr[i][j];
	}
	return (0);
}

int	ft_quickfill_for_collectibles(t_game *g)
{
	(void) g;
	return (0);
}

int	ft_quickfill_for_exit(t_game *g)
{
	(void) g;
	return (0);
}
