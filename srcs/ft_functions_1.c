/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absalhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 03:50:15 by absalhi           #+#    #+#             */
/*   Updated: 2022/12/23 23:03:49 by absalhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_occurences(char *str, char c)
{
	int	i;
	int	r;

	r = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			r++;
	return (r);
}

int	ft_free_tab(void **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (1);
}

int	ft_free_double_int(int **tab, size_t size)
{
	int	i;

	i = -1;
	while ((size_t)++i < size)
		free(tab[i]);
	free(tab);
	return (1);
}

int	ft_free(void *ptr)
{
	free(ptr);
	return (1);
}

int	ft_close(int fd)
{
	close(fd);
	return (0);
}
