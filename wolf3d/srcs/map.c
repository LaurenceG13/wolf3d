/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@41.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1017/11/04 11:09:31 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:04:57 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_init_map(t_param *s)
{
	int i;
	int j;

	if (!(s->world_map = ft_memalloc_tab_int(s->map_width, s->map_height)))
		return (ft_error_malloc_tab(s));
	i = 0;
	while (i < s->map_width)
	{
		j = 0;
		s->world_map[i][j] = 0;
		while (j < s->map_height)
		{
			s->world_map[i][j] = 0;
			if (((j >= 0 && j <= 21) && (i == 12 || i == 3)) || \
					((j >= 3 && j <= 24) && (i == 15 || i == 6)) ||\
					(((j >= 0 && j <= 9) || (j >= 12 && j <= 23)) \
						&& (i == 18 || i == 9))\
					|| (i == 0 || j == 0 || i == 23 || j == 23) || \
					((i == 0 || j == 0 || i == 23 || j == 23)))
				s->world_map[i][j] = 1;
			j++;
		}
		i++;
	}
	return (0);
}
