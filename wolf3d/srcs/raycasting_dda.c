/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:10:56 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:05:09 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	ft_raycasting_dda(t_param *s)
{
	while (s->hit == 0)
	{
		if (s->side_dist_x < s->side_dist_y)
		{
			s->side_dist_x += s->delta_dist_x;
			s->map_x += s->step_x;
			s->side = 0;
		}
		else
		{
			s->side_dist_y += s->delta_dist_y;
			s->map_y += s->step_y;
			s->side = 1;
		}
		if (s->world_map[s->map_x][s->map_y] > 0)
			s->hit = 1;
	}
	return (0);
}
