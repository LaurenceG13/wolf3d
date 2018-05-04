/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 10:05:38 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:04:40 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_keycode_move(t_param *s)
{
	if (s->key == 126)
	{
		if (!(s->world_map[(int)(s->pos_x + s->dir_x * s->move_speed)]\
		[(int)(s->pos_y)]))
			s->pos_x += s->dir_x * s->move_speed;
		if (!(s->world_map[(int)(s->pos_x)][(int)(s->pos_y + s->dir_y * \
			s->move_speed)]))
			s->pos_y += s->dir_y * s->move_speed;
	}
	else if (s->key == 125)
	{
		if (!(s->world_map[(int)(s->pos_x - s->dir_x * s->move_speed)]\
		[(int)(s->pos_y)]))
			s->pos_x -= s->dir_x * s->move_speed;
		if (!(s->world_map[(int)(s->pos_x)][(int)(s->pos_y - s->dir_y * \
			s->move_speed)]))
			s->pos_y -= s->dir_y * s->move_speed;
	}
	ft_again(s);
}

void		ft_keycode_rotate(t_param *s)
{
	double old_dir_x;
	double old_plane_x;
	double r;

	r = s->rot_speed;
	if (s->key == 124)
	{
		old_dir_x = s->dir_x;
		s->dir_x = s->dir_x * cos(-r) - s->dir_y * sin(-r);
		s->dir_y = old_dir_x * sin(-r) + s->dir_y * cos(-r);
		old_plane_x = s->plane_x;
		s->plane_x = s->plane_x * cos(-r) - s->plane_y * sin(-r);
		s->plane_y = old_plane_x * sin(-r) + s->plane_y * cos(-r);
	}
	else if (s->key == 123)
	{
		old_dir_x = s->dir_x;
		s->dir_x = s->dir_x * cos(r) - s->dir_y * sin(r);
		s->dir_y = old_dir_x * sin(r) + s->dir_y * cos(r);
		old_plane_x = s->plane_x;
		s->plane_x = s->plane_x * cos(r) - s->plane_y * sin(r);
		s->plane_y = old_plane_x * sin(r) + s->plane_y * cos(r);
	}
	ft_again(s);
}

int			ft_keycode(int keycode, void *tmp)
{
	t_param	*s;

	s = (t_param *)tmp;
	s->key = keycode;
	if (s->key == 53)
	{
		ft_free_before_leave(s);
		exit(0);
	}
	else if (s->key == 36)
	{
		ft_init_one(s);
		ft_again(s);
	}
	else if (s->key == 125 || s->key == 126)
		ft_keycode_move(s);
	else if (s->key == 123 || s->key == 124)
		ft_keycode_rotate(s);
	return (0);
}

int			ft_close(void *blabla)
{
	t_param	*s;

	s = (t_param *)blabla;
	ft_free_before_leave(s);
	exit(1);
	return (0);
}

int			ft_events(t_param *s)
{
	mlx_hook(s->win, 17, 0L, ft_close, s);
	mlx_hook(s->win, 2, 2, ft_keycode, s);
	return (0);
}
