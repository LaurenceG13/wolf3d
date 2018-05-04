/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:33:05 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:05:01 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_again(t_param *s)
{
	mlx_clear_window(s->mlx, s->win);
	mlx_destroy_image(s->mlx, s->img);
	ft_gameloop(s);
}

int		ft_usage(void)
{
	ft_putendl("Usage : ./worlf3d");
	return (1);
}

void	ft_init_one(t_param *s)
{
	s->pos_x = 22;
	s->pos_y = 12;
	s->dir_x = -1;
	s->dir_y = 0;
	s->plane_x = 0;
	s->plane_y = 0.66;
	s->x_win = 1280;
	s->y_win = 720;
	s->move_speed = 1.0001;
	s->rot_speed = 0.1;
}

int		ft_gameloop(t_param *s)
{
	int		x;

	if (!(s->img = mlx_new_image(s->mlx, s->x_win, s->y_win)))
		return (ft_error_malloc_img(s));
	if (!(s->str_img = (int *)mlx_get_data_addr(s->img, &(s->bpp), \
					&(s->s_l), &(s->endian))))
		return (ft_error_malloc_str_img(s));
	ft_draw_img(s);
	x = 0;
	while (x < s->x_win)
	{
		ft_raycasting_init(s, x);
		ft_raycasting_dda(s);
		ft_raycasting_wall(s, x);
		x++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	return (0);
}

int		main(void)
{
	t_param	*s;

	if (!(s = (t_param *)ft_memalloc(sizeof(t_param))))
		return (ft_error_malloc_struct());
	ft_init_struct(s);
	ft_init_one(s);
	if (ft_init_map(s) == 1)
		return (ft_error_malloc_map(s));
	if (!(s->mlx = mlx_init()))
		return (ft_error_malloc_minilib(s));
	if (!(s->win = mlx_new_window(s->mlx, s->x_win, s->y_win, \
					"Wolf3d")))
		return (ft_error_malloc_window(s));
	ft_gameloop(s);
	ft_events(s);
	mlx_loop(s->mlx);
	return (0);
}
