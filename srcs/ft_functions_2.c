/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <absalhi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 03:24:02 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/28 21:45:54 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_coords	ft_coords(int r, int c)
{
	t_coords	pos;

	pos.r = r;
	pos.c = c;
	return (pos);
}

int	ft_nb_count_occurences(int *arr, int n, size_t size)
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
