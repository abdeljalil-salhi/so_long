/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 05:46:37 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/25 15:35:39 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define ERROR ", must be all walls."
#define OCCURENCES 7

int	ft_check_borders(t_game *g)
{
	int	i;
	int	j;

	j = -1;
	while (++j < g->win.width)
	{
		if (g->map.arr[0][j] != 1)
			return (ft_error(g, "Invalid top border, ERROR"));
		if (g->map.arr[g->win.height - 1][j] != 1)
			return (ft_error(g, "Invalid bottom border, ERROR"));
	}
	i = -1;
	while (++i < g->win.height)
	{
		if (g->map.arr[i][0] != 1)
			return (ft_error(g, "Invalid left border, ERROR"));
		if (g->map.arr[i][g->win.width - 1] != 1)
			return (ft_error(g, "Invalid right border, ERROR"));
	}
	return (0);
}

static int	ft_nb_count_occurences(int *arr, int n, size_t size)
{
	int	i;
	int	r;

	r = 0;
	i = -1;
	while ((size_t)++i < size)
		if (arr[i] == n)
			r++;
	return (r);
}

static void	ft_display_infos(t_game *g, int occur[OCCURENCES])
{
	ft_printf("Displaying informations about (%s)...\n\n", g->map.file.name);
	ft_printf("The width of this map is %d.\n", g->win.width);
	ft_printf("The height of this map is %d.\n", g->win.height);
	ft_printf("This map contains %d empty space(s).\n", occur[0]);
	ft_printf("This map contains %d wall(s).\n", occur[1]);
	ft_printf("This map contains %d player(s).\n", occur[2]);
	ft_printf("This map contains %d exit(s).\n", occur[3]);
	ft_printf("This map contains %d collectible(s).\n", occur[4]);
	if (occur[5] + occur[6] == 1)
		ft_printf("This map contains %d enemy.\n\n", occur[5] + occur[6]);
	else
		ft_printf("This map contains %d enemies.\n\n", occur[5] + occur[6]);
}

int	ft_check_uniqueness(t_game *g)
{
	int	i;
	int	j;
	int	occur[OCCURENCES];

	ft_bzero(occur, OCCURENCES * sizeof(int));
	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < OCCURENCES)
			occur[j] += ft_nb_count_occurences(g->map.arr[i], j, g->win.width);
	}
	ft_display_infos(g, occur);
	if (occur[2] != 1)
		return (ft_error(g, "Use one player (and only one) !!"));
	if (occur[3] != 1)
		return (ft_error(g, "Use one exit (and only one) !!"));
	if (!occur[4])
		return (ft_error(g, "Use at least one collectible !!"));
	g->n_collectibles = occur[4];
	g->n_enemies = occur[5] + occur[6];
	return (0);
}
