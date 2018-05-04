/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:45:33 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:05:33 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_free_before_leave(t_param *s)
{
	ft_free_tab_int(s->world_map, s->map_width);
	mlx_destroy_image(s->mlx, s->img);
	mlx_destroy_window(s->mlx, s->win);
	ft_free_struct(s);
}

void	ft_free_struct(t_param *s)
{
	if (s != NULL)
	{
		free(s);
		s = NULL;
	}
}

int		**ft_memalloc_tab_int(int size_i, int size_j)
{
	int		**tab;
	int		i;
	int		j;

	if (!(tab = (int **)malloc(sizeof(int *) * size_i)))
		return (NULL);
	i = 0;
	while (i < size_i)
	{
		j = 0;
		if (!(tab[i] = (int *)malloc(sizeof(int) * size_j)))
			return (NULL);
		while (j < size_j)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_free_tab_int(int **tab, int size_i)
{
	int		i;

	if (tab != NULL)
	{
		i = 0;
		while (i < size_i)
		{
			if (tab[i] != NULL)
			{
				free(tab[i]);
				tab[i] = NULL;
				i++;
			}
		}
		free(tab);
		tab = NULL;
	}
}
