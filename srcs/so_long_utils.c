/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:18:57 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/17 05:44:52 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_print_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->win.height)
	{
		j = -1;
		while (++j < g->win.width)
			ft_printf("%d", g->map.arr[i][j]);
		ft_printf("\n");
	}
}

int	ft_check_and_init(t_game *g, char *map)
{
	g->map.file.name = map;
	if (ft_check_extension(g))
		return (1);
	if (ft_read_file(g))
		return (1);
	if (ft_init_map(g))
		return (1);
	if (ft_check_map(g))
		return (1);
	ft_print_map(g);
	return (0);
}
