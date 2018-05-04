/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:11:14 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:05:27 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_raycasting_color(t_param *s, int x)
{
	if (s->side == 1)
	{
		if (s->step_y > 0)
			s->color = 0xffd0b6;
		else
			s->color = 0xffb6c1;
	}
	else
	{
		if (s->step_x > 0)
			s->color = 0xb6c1ff;
		else
			s->color = 0xc1ffb6;
	}
	ft_draw_vertical(s, x, s->draw_start, s->draw_end);
	return (0);
}

int		ft_raycasting_wall(t_param *s, int x)
{
	if (s->side == 0)
		s->perp_wall_dist = ((s->map_x - s->ray_pos_x + (1 - s->step_x) / 2) \
				/ s->ray_dir_x);
	else
		s->perp_wall_dist = ((s->map_y - s->ray_pos_y + (1 - s->step_y) / 2) \
				/ s->ray_dir_y);
	s->line_height = ((int)(s->y_win / s->perp_wall_dist));
	s->draw_start = (s->y_win - s->line_height) / 2;
	if (s->draw_start < 0)
		s->draw_start = 0;
	s->draw_end = (s->y_win + s->line_height) / 2;
	if (s->draw_end >= s->y_win)
		s->draw_end = s->y_win - 1;
	ft_raycasting_color(s, x);
	return (0);
}
