/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_minilib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:04:08 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:04:10 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_error_malloc_minilib(t_param *s)
{
	ft_free_tab_int(s->world_map, s->map_width);
	ft_free_struct(s);
	ft_putendl("Error : malloc minilibx failed");
	return (1);
}

int		ft_error_malloc_window(t_param *s)
{
	ft_free_tab_int(s->world_map, s->map_width);
	ft_free_struct(s);
	ft_putendl("Error : malloc window failed");
	return (1);
}

int		ft_error_malloc_img(t_param *s)
{
	ft_free_tab_int(s->world_map, s->map_width);
	mlx_destroy_window(s->mlx, s->win);
	ft_free_struct(s);
	ft_putendl("Error : malloc str_img failed");
	return (1);
}

int		ft_error_malloc_str_img(t_param *s)
{
	ft_free_tab_int(s->world_map, s->map_width);
	mlx_destroy_image(s->mlx, s->img);
	mlx_destroy_window(s->mlx, s->win);
	ft_free_struct(s);
	ft_putendl("Error : malloc str_img failed");
	return (1);
}
