/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 11:10:44 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/07 20:48:08 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_init_three(t_param *s)
{
	if (s->ray_dir_x < 0)
	{
		s->step_x = -1;
		s->side_dist_x = (s->ray_pos_x - s->map_x) * s->delta_dist_x;
	}
	else
	{
		s->step_x = 1;
		s->side_dist_x = (s->map_x + 1.0 - s->ray_pos_x) * s->delta_dist_x;
	}
	if (s->ray_dir_y < 0)
	{
		s->step_y = -1;
		s->side_dist_y = (s->ray_pos_y - s->map_y) * s->delta_dist_y;
	}
	else
	{
		s->step_y = 1;
		s->side_dist_y = (s->map_y + 1.0 - s->ray_pos_y) * s->delta_dist_y;
	}
}

void	ft_init_two(t_param *s, int x)
{
	s->camera_x = 2 * x / (double)s->x_win - 1;
	s->ray_pos_x = s->pos_x;
	s->ray_pos_y = s->pos_y;
	s->ray_dir_x = s->dir_x + s->plane_x * s->camera_x;
	s->ray_dir_y = s->dir_y + s->plane_y * s->camera_x;
	s->map_x = (int)s->ray_pos_x;
	s->map_y = (int)s->ray_pos_y;
	s->delta_dist_x = sqrt(1 + (s->ray_dir_y * s->ray_dir_y) / (s->ray_dir_x\
				* s->ray_dir_x));
	s->delta_dist_y = sqrt(1 + (s->ray_dir_x * s->ray_dir_x) / (s->ray_dir_y\
				* s->ray_dir_y));
	s->hit = 0;
}

int		ft_raycasting_init(t_param *s, int x)
{
	ft_init_two(s, x);
	ft_init_three(s);
	return (0);
}
