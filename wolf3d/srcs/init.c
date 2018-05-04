/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:49:00 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:04:46 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_init_struct_bis(t_param *s)
{
	s->ray_pos_x = 0;
	s->ray_pos_y = 0;
	s->ray_dir_x = 0;
	s->ray_dir_y = 0;
	s->map_x = 0;
	s->map_y = 0;
	s->side_dist_x = 0;
	s->side_dist_x = 0;
	s->delta_dist_x = 0;
	s->delta_dist_y = 0;
	s->perp_wall_dist = 0;
	s->step_x = 0;
	s->step_y = 0;
	s->hit = 0;
	s->side = 0;
	s->line_height = 0;
	s->draw_start = 0;
	s->draw_end = 0;
	s->move_speed = 0;
	s->rot_speed = 0;
}

void	ft_init_struct(t_param *s)
{
	s->map_width = 24;
	s->map_height = 24;
	s->x_win = 0;
	s->y_win = 0;
	s->mlx = NULL;
	s->win = NULL;
	s->img = NULL;
	s->key = 0;
	s->str_img = NULL;
	s->bpp = 0;
	s->s_l = 0;
	s->endian = 0;
	s->color = 0;
	s->world_map = NULL;
	s->pos_x = 0;
	s->pos_y = 0;
	s->dir_x = 0;
	s->dir_y = 0;
	s->plane_x = 0;
	s->plane_y = 0;
	s->camera_x = 0;
}
