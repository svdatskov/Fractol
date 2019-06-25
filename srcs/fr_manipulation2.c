/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_manipulation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:52:41 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:37:18 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(int button, int x, int y, t_param *param)
{
	t_zoom z;

	z.cnt_re = 0 / (0.5 * param->zoom * IMG_WIDTH) + param->move_x;
	z.cnt_im = 0 / (0.5 * param->zoom * HEIGHT) + param->move_y;
	z.m_re = 1.5 * (((double)x - MENU) - IMG_WIDTH / 2)
			/ (0.5 * param->zoom * IMG_WIDTH) + param->move_x;
	z.m_im = ((double)y - HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	param->move_x -= z.cnt_re - z.m_re;
	param->move_y -= z.cnt_im - z.m_im;
	if (button == 4)
		param->zoom < 207677431915418 ? param->zoom *= 1.05 : param->zoom;
	if (button == 5)
		param->zoom > 0.0005 ? param->zoom /= 1.05 : param->zoom;
	z.cnt_re = 0 / (0.5 * param->zoom * IMG_WIDTH) + param->move_x;
	z.cnt_im = 0 / (0.5 * param->zoom * HEIGHT) + param->move_y;
	z.m_re = 1.5 * (((double)x - MENU) - IMG_WIDTH / 2)
			/ (0.5 * param->zoom * IMG_WIDTH) + param->move_x;
	z.m_im = ((double)y - HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	param->move_x += z.cnt_re - z.m_re;
	param->move_y += z.cnt_im - z.m_im;
	ft_bzero(param->data_ptr, IMG_WIDTH * 4 * HEIGHT);
	ft_draw_fractal(param);
}

void	ft_move(int keycode, t_param *param)
{
	ft_bzero(param->data_ptr, IMG_WIDTH * 4 * HEIGHT);
	if (keycode == 0)
	{
		param->move_x += 0.04 / param->zoom;
		ft_draw_fractal(param);
	}
	else if (keycode == 2)
	{
		param->move_x -= 0.04 / param->zoom;
		ft_draw_fractal(param);
	}
	else if (keycode == 13)
	{
		param->move_y += 0.04 / param->zoom;
		ft_draw_fractal(param);
	}
	else if (keycode == 1)
	{
		param->move_y -= 0.04 / param->zoom;
		ft_draw_fractal(param);
	}
}
