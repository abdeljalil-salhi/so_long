/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:18:09 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/27 02:12:42 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

struct s_rf
{
	size_t	rows;
	size_t	len;
	char	*row;
};

struct s_im
{
	int		i;
	int		j;
	char	*row;
};

struct s_cm
{
	int	i;
	int	j;
};

int	ft_check_extension(t_game *g)
{
	char	**split;
	int		i;
	int		occur;

	occur = ft_count_occurences(g->map.file.name, '.');
	if (!occur)
		return (ft_error(g, "Where is your extension mate ?? o.O"));
	if (occur > 1)
		return (ft_error(g, "WDYM multiple points in your filename ??"));
	split = ft_split(g->map.file.name, '.');
	if (!split)
		return (ft_error(g, "UMM SORRY... That's on me, ft_split failed xD"));
	i = -1;
	while (split[++i])
		;
	if (i != 2)
		return (ft_free_tab((void **) split));
	if (ft_strncmp(split[1], "ber", 4))
		return (ft_free_tab((void **) split)
			+ ft_error(g, "Invalid extension buddy.. Please use '.ber'"));
	ft_free_tab((void **) split);
	return (0);
}

int	ft_read_file(t_game *g)
{
	struct s_rf	s;

	s.len = 0;
	s.rows = 0;
	g->map.file.fd = open(g->map.file.name, O_RDONLY);
	if (g->map.file.fd == -1)
		return (ft_error(g, "File not found."));
	while (1)
	{
		s.row = get_next_line(g->map.file.fd);
		if (!s.row)
			break ;
		if (ft_strlen(s.row) != s.len && s.rows)
			return (ft_error(g, "The length of rows differs."));
		s.len = ft_strlen(s.row);
		s.rows++;
		free(s.row);
	}
	free(s.row);
	g->win.width = s.len - 1;
	g->win.height = s.rows;
	close(g->map.file.fd);
	return (0);
}

int	ft_init_map(t_game *g)
{
	struct s_im	s;

	g->map.file.fd = open(g->map.file.name, O_RDONLY);
	if (g->map.file.fd == -1)
		return (ft_error(g, "Sorry, an error occured in map init."));
	g->map.arr = (int **) ft_calloc(g->win.height, sizeof(int *));
	if (!g->map.arr)
		return (ft_error(g, "map_utils.c: (int **) ft_calloc failed."));
	s.i = -1;
	while (++s.i < g->win.height)
	{
		g->map.arr[s.i] = (int *) ft_calloc(g->win.width, sizeof(int));
		if (!g->map.arr[s.i])
			return (ft_free(g->map.arr)
				+ ft_free_double_int(g->map.arr, (size_t) s.i)
				+ ft_error(g, "map_utils.c: (int *) ft_calloc failed."));
		s.row = get_next_line(g->map.file.fd);
		if (!s.row)
			return (ft_free_tab((void **)g->map.arr)
				+ ft_error(g, "map_utils.c: get_next_line failed."));
		s.j = -1;
		while (++s.j < g->win.width)
			g->map.arr[s.i][s.j] = ft_set_ceil_type(g, s.row[s.j]);
		free(s.row);
	}
	g->allocated.map = 1;
	return (ft_close(g->map.file.fd));
}

int	ft_check_map(t_game *g)
{
	struct s_cm	s;

	s.i = -1;
	while (++s.i < g->win.height)
	{
		s.j = -1;
		while (++s.j < g->win.width)
			if (g->map.arr[s.i][s.j] > 69)
				return (1);
	}
	if (ft_check_borders(g))
		return (1);
	if (ft_check_uniqueness(g))
		return (1);
	return (0);
}

int	ft_set_ceil_type(t_game *g, char c)
{
	if (c == '1' || c == '0')
		return (c - 48);
	else if (c == 'P' || c == 'p')
		return (2);
	else if (c == 'E' || c == 'e')
		return (3);
	else if (c == 'C' || c == 'c')
		return (4);
	else if (c == 'H' || c == 'h')
		return (5);
	else if (c == 'V' || c == 'v')
		return (6);
	return (ft_error(g, "JUST PROTECTION IN CASE ?? Invalid CHARACTER.") + 69);
}
