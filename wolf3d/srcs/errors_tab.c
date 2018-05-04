/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 00:04:26 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/08 00:04:29 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		ft_error_malloc_struct(void)
{
	ft_putendl("Error : malloc struc failed");
	return (1);
}

int		ft_error_malloc_tab(t_param *s)
{
	ft_free_struct(s);
	ft_putendl("Error : malloc tab failed");
	return (1);
}

int		ft_error_malloc_map(t_param *s)
{
	ft_free_struct(s);
	ft_putendl("Error : malloc map failed");
	return (1);
}
