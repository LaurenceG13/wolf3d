/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagirard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:30:34 by lagirard          #+#    #+#             */
/*   Updated: 2017/11/07 19:59:12 by lagirard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	int			key;
	int			*str_img;
	int			bpp;
	int			s_l;
	int			endian;
	int			color;
	int			map_width;
	int			map_height;
	int			x_win;
	int			y_win;
	int			**world_map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_pos_x;
	double		ray_pos_y;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		move_speed;
	double		rot_speed;
}				t_param;

int				main(void);
void			ft_init_struct(t_param *s);
int				ft_init_map(t_param *s);
int				ft_error_malloc_struct(void);
int				ft_error_malloc_minilib(t_param *s);
int				ft_error_malloc_window(t_param *s);
int				ft_error_malloc_img(t_param *s);
int				ft_error_malloc_str_img(t_param *s);
int				ft_error_malloc_tab(t_param *s);
int				ft_error_malloc_map(t_param *s);
int				ft_error_raycasting_init(t_param *s);
int				ft_error_raycasting_dda(t_param *s);
int				ft_error_raycasting_wall(t_param *s);
int				**ft_memalloc_tab_int(int size_i, int size_j);
void			ft_free_struct(t_param *s);
void			ft_free_pointer(void *p);
void			ft_free_tab_int(int **tab, int size_i);
void			ft_again(t_param *s);
int				ft_events(t_param *s);
int				ft_keycode(int keycode, void *tmp);
int				ft_gameloop(t_param *s);
int				ft_raycasting_init(t_param *s, int x);
int				ft_raycasting_dda(t_param *s);
int				ft_raycasting_wall(t_param *s, int x);
int				ft_draw_vertical(t_param *s, int x, int y_a, int y_b);
void			ft_draw_img(t_param *s);
void			ft_put_point_img(t_param *s, int x, int y, int color);
void			ft_init_struct(t_param *s);
void			ft_init_one(t_param *s);
void			ft_free_before_leave(t_param *s);

#endif
