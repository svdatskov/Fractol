/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:25:14 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/22 16:25:15 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# define WIDTH 1350
# define HEIGHT 800
# define IMG_WIDTH 1100
# define MENU (WIDTH - IMG_WIDTH)
# define THRD 4

typedef struct		s_param {
	char			*name;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	int				bpp;
	int				number;
	int				size_line;
	int				endian;
	double			move_x;
	double			move_y;
	int				max_iterations;
	double			zoom;
	double			c_re;
	double			c_im;
	int				locker;
}					t_param;

typedef struct		s_thread
{
	int				start;
	int				end;
	t_param			*param;
}					t_thread;

typedef struct		s_fr {
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			re_sqr;
	double			im_sqr;
	int				width;
	int				height;
	int				x;
	int				y;
	int				i;
	double			p_re;
	double			p_im;
}					t_fr;

typedef struct		s_rgb {
	double			r;
	double			g;
	double			b;
	double			n;
}					t_rgb;

typedef struct		s_zoom {
	double			m_re;
	double			m_im;
	double			cnt_re;
	double			cnt_im;
}					t_zoom;

void				ft_error(int error);
void				ft_julia(char *img_data, t_param *param, t_fr fr);
void				ft_mandelbrot(char *img_data, t_param *param, t_fr fr);
void				ft_burningship(char *img_data, t_param *param, t_fr fr);
void				ft_color(char *img_data, t_fr fr, int max);
int					ft_check(char *name);
t_param				*mlx_initial(char *name);
void				ft_zoom(int button, int x, int y, t_param *param);
void				ft_move(int keycode, t_param *param);
void				set_param(t_param *param);
void				ft_base(int keycode, t_param *param);
void				print_menu(t_param *param);
void				ft_move_mouse(int x, int y, t_param *param);
void				ft_locker(t_param *param);
void				ft_draw_fractal(t_param *param);
void				mlx_manipulation(t_param *param);
void				ft_change_it(int keycode, t_param *param);
void				ft_per_celtic(char *img_data, t_param *param, t_fr fr);
void				ft_cub_man(char *img_data, t_param *param, t_fr fr);
void				ft_mandelbrot4(char *img_data, t_param *param, t_fr fr);
void				ft_cubic_man(char *img_data, t_param *param, t_fr fr);
void				ft_celtic_heart(char *img_data, t_param *param, t_fr fr);

#endif
