/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_manipulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:24:42 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:36:38 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_mouse(int x, int y, t_param *param)
{
	double step_re;
	double step_im;

	if (param->locker == -1)
	{
		step_re = 3.6 / IMG_WIDTH;
		step_im = 2.4 / HEIGHT;
		param->c_re = x * step_re - 2.5;
		param->c_im = (y * -1) * step_im + 1.2;
		ft_bzero(param->data_ptr, IMG_WIDTH * 4 * HEIGHT);
		ft_draw_fractal(param);
	}
}

void	ft_base(int keycode, t_param *param)
{
	ft_bzero(param->data_ptr, IMG_WIDTH * 4 * HEIGHT);
	if (keycode == 29)
		set_param(param);
	ft_draw_fractal(param);
}

void	ft_locker(t_param *param)
{
	param->locker *= -1;
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	ft_draw_fractal(param);
	print_menu(param);
}

void	ft_change_it(int keycode, t_param *param)
{
	if (keycode == 14)
		param->max_iterations += 1;
	else if (keycode == 12)
		param->max_iterations -= 1;
	ft_bzero(param->data_ptr, IMG_WIDTH * 4 * HEIGHT);
	ft_draw_fractal(param);
}
