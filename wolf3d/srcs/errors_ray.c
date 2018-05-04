/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:04:18 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:04:19 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_error_raycasting_init(t_param *s)
{
	ft_free_before_leave(s);
	ft_putendl("Error : ft_error_raycasting_INIT failed");
	return (1);
}

int		ft_error_raycasting_dda(t_param *s)
{
	ft_free_before_leave(s);
	ft_putendl("Error : ft_error_raycasting_DDA failed");
	return (1);
}

int		ft_error_raycasting_wall(t_param *s)
{
	ft_free_before_leave(s);
	ft_putendl("Error : ft_error_raycasting_WALL failed");
	return (1);
}
