/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 13:50:23 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:05:38 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_draw_img(t_param *s)
{
	int		middle;
	int		y;
	int		x;

	middle = s->y_win / 2;
	y = 0;
	while (y < s->y_win)
	{
		if (y > middle)
			s->color = 0x1d2531;
		else
			s->color = 0x125182;
		x = 0;
		while (x < s->x_win)
		{
			ft_put_point_img(s, x, y, s->color);
			x++;
		}
		y++;
	}
}

void	ft_put_point_img(t_param *s, int x, int y, int color)
{
	if (x < s->x_win && y < s->y_win && x >= 0 && y >= 0)
	{
		s->str_img[y * s->x_win + x] = color;
	}
}

int		ft_draw_vertical(t_param *s, int x, int y_a, int y_b)
{
	int		tmp_y;

	if (y_a < y_b)
	{
		tmp_y = y_a;
		while (tmp_y <= y_b)
		{
			ft_put_point_img(s, x, tmp_y, s->color);
			tmp_y++;
		}
	}
	if (y_b < y_a)
	{
		tmp_y = y_b;
		while (tmp_y <= y_a)
		{
			ft_put_point_img(s, x, tmp_y, s->color);
			tmp_y++;
		}
	}
	if (y_a == y_b)
		ft_put_point_img(s, x, tmp_y, s->color);
	return (0);
}
