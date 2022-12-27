/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:06:16 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 12:08:06 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < g->win.width)
			ft_printf("%d", g->quickfill.dc[i][j]);
		ft_printf("\n");
	}
}

int	ft_deep_copy_map(t_game *g)
{
	int	i;
	int	j;

	g->quickfill.dc = (int **) ft_calloc(g->win.height, sizeof(int *));
	if (!g->quickfill.dc)
		return (ft_error(g, "ft_quick_fill.c: (int **) ft_calloc failed."));
	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		g->quickfill.dc[i] = (int *) ft_calloc(g->win.width, sizeof(int));
		if (!g->quickfill.dc[i])
			return (ft_free(g->quickfill.dc)
				+ ft_free_double_int(g->quickfill.dc, (size_t) i)
				+ ft_error(g, "ft_quick_fill.c: (int *) ft_calloc failed."));
		while (++j < g->win.width)
			g->quickfill.dc[i][j] = g->map.arr[i][j];
	}
	return (0);
}

void	ft_quickfill_norm(t_game *g, int r, int c, int depth)
{
	g->quickfill.dc[r][c] = QUICKFILLED;
	ft_quickfill(g, ft_coords(r, c), depth + 1);
}

int	ft_quickfill(t_game *g, t_coords p, int depth)
{
	if (p.r - 1 > 0 && (g->quickfill.dc[p.r - 1][p.c] == 0
		|| g->quickfill.dc[p.r - 1][p.c] == 3
		|| g->quickfill.dc[p.r - 1][p.c] == 4
		|| g->quickfill.dc[p.r - 1][p.c] == 5
		|| g->quickfill.dc[p.r - 1][p.c] == 6))
	{
		g->quickfill.dc[p.r - 1][p.c] = QUICKFILLED;
		ft_quickfill(g, ft_coords(p.r - 1, p.c), depth + 1);
	}
		//ft_quickfill_norm(g, p.r - 1, p.c, depth);
	if (p.c + 1 < g->win.width && (g->quickfill.dc[p.r][p.c + 1] == 0
		|| g->quickfill.dc[p.r][p.c + 1] == 3
		|| g->quickfill.dc[p.r][p.c + 1] == 4
		|| g->quickfill.dc[p.r][p.c + 1] == 5
		|| g->quickfill.dc[p.r][p.c + 1] == 6))
	{
		g->quickfill.dc[p.r][p.c + 1] = QUICKFILLED;
		ft_quickfill(g, ft_coords(p.r, p.c + 1), depth + 1);
	}
		//ft_quickfill_norm(g, p.r, p.c + 1, depth);
	if (p.r + 1 < g->win.height && (g->quickfill.dc[p.r + 1][p.c] == 0
		|| g->quickfill.dc[p.r + 1][p.c] == 3
		|| g->quickfill.dc[p.r + 1][p.c] == 4
		|| g->quickfill.dc[p.r + 1][p.c] == 5
		|| g->quickfill.dc[p.r + 1][p.c] == 6))
	{
		g->quickfill.dc[p.r + 1][p.c] = QUICKFILLED;
		ft_quickfill(g, ft_coords(p.r + 1, p.c), depth + 1);
	}
		//ft_quickfill_norm(g, p.r + 1, p.r, depth);
	if (p.c - 1 > 0 && (g->quickfill.dc[p.r][p.c - 1] == 0
		|| g->quickfill.dc[p.r][p.c - 1] == 3
		|| g->quickfill.dc[p.r][p.c - 1] == 4
		|| g->quickfill.dc[p.r][p.c - 1] == 5
		|| g->quickfill.dc[p.r][p.c - 1] == 6))
	{
		g->quickfill.dc[p.r][p.c - 1] = QUICKFILLED;
		ft_quickfill(g, ft_coords(p.r, p.c - 1), depth + 1);
	}
		//ft_quickfill_norm(g, p.r, p.c - 1, depth);
	//if (depth == 1)
	//	ft_print_map(g);
	if (depth > g->quickfill.depth)
		g->quickfill.depth = depth;
	return (0);
}

/*
int	ft_quickfill_for_collectibles(t_game *g, t_coords p, int depth)
{
	int	i;
	int	occur;

	ft_printf("%d\n", g->quickfill.dc[p.r - 1][p.c]);
	if (p.r - 1 > 0 && (g->quickfill.dc[p.r - 1][p.c] == 0
			|| g->quickfill.dc[p.r - 1][p.c] == 4))
		g->quickfill.dc[p.r - 1][p.c] = ft_quickfill_for_collectibles(
				g, ft_coords(p.r - 1, p.c), depth + 1);
	ft_printf("%d\n", g->quickfill.dc[p.r][p.c + 1]);
	if (p.c + 1 < g->win.width && (g->quickfill.dc[p.r][p.c + 1] == 0
			|| g->quickfill.dc[p.r][p.c + 1] == 4))
		g->quickfill.dc[p.r][p.c + 1] = ft_quickfill_for_collectibles(
				g, ft_coords(p.r, p.c + 1), depth + 1);
	ft_printf("%d\n", g->quickfill.dc[p.r + 1][p.c]);
	if (p.r + 1 < g->win.height && (g->quickfill.dc[p.r + 1][p.c] == 0
			|| g->quickfill.dc[p.r + 1][p.c] == 4))
		g->quickfill.dc[p.r + 1][p.c] = ft_quickfill_for_collectibles(
				g, ft_coords(p.r + 1, p.c), depth + 1);
	ft_printf("%d\n", g->quickfill.dc[p.r][p.c - 1]);
	if (p.c - 1 > 0 && (g->quickfill.dc[p.r][p.c - 1] == 0
			|| g->quickfill.dc[p.r][p.c - 1] == 4))
		g->quickfill.dc[p.r][p.c - 1] = ft_quickfill_for_collectibles(
				g, ft_coords(p.r, p.c - 1), depth + 1);
	i = -1;
	occur = 0;
	if (depth == 1)
		while (++i < g->win.height)
			occur += ft_nb_count_occurences(g->quickfill.dc[i], 4, g->win.width);
	ft_printf("remaining %d\n", occur);
	if (depth == 1 && occur)
	{
		ft_print_map(g);
		return (ft_error(g, "Invalid path to collectibles."));
	}
	return (9 * !(depth == 1));
}
*/

int	ft_check_collectibles(t_game *g)
{
	int	i;
	int	occur;

	i = -1;
	occur = 0;
	while (++i < g->win.height)
		occur += ft_nb_count_occurences(g->quickfill.dc[i], 4, g->win.width);
	return (1 + (1 && occur)
		- ft_error(g, "Invalid path to collectibles."));
}

int	ft_check_exit(t_game *g)
{
	int	i;
	int	occur;

	i = -1;
	occur = 0;
	while (++i < g->win.height)
		occur += ft_nb_count_occurences(g->quickfill.dc[i], 3, g->win.width);
	return (1 + (1 && occur)
		- ft_error(g, "Invalid path to the exit."));
}
