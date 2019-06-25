/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:34:29 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:38:05 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot4(char *img_data, t_param *param, t_fr fr)
{
	fr.p_re = 1.5 * (fr.x - (double)fr.width / 2)
			/ (0.5 * param->zoom * fr.width) + param->move_x;
	fr.p_im = (fr.y - (double)HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	fr.new_re = 0;
	fr.new_im = 0;
	fr.old_re = 0;
	fr.old_im = 0;
	fr.i = 0;
	while (fr.i < param->max_iterations &&
	(fr.new_re * fr.new_re + fr.new_im * fr.new_im) < 4)
	{
		fr.old_re = fr.new_re;
		fr.old_im = fr.new_im;
		fr.re_sqr = fr.old_re * fr.old_re;
		fr.im_sqr = fr.old_im * fr.old_im;
		fr.new_re = fr.re_sqr * fr.re_sqr + fr.im_sqr *
				fr.im_sqr - 6 * fr.re_sqr * fr.im_sqr + fr.p_re;
		fr.new_im = 4 * fr.old_re * fr.old_im *
				(fr.re_sqr - fr.im_sqr) + fr.p_im;
		fr.i++;
	}
	ft_color(img_data, fr, param->max_iterations);
}

void	ft_cubic_man(char *img_data, t_param *param, t_fr fr)
{
	fr.p_re = 1.5 * (fr.x - (double)fr.width / 2)
			/ (0.5 * param->zoom * fr.width) + param->move_x;
	fr.p_im = (fr.y - (double)HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	fr.new_re = 0;
	fr.new_im = 0;
	fr.old_re = 0;
	fr.old_im = 0;
	fr.i = 0;
	while (fr.i < param->max_iterations &&
	(fr.new_re * fr.new_re + fr.new_im * fr.new_im) < 4)
	{
		fr.old_re = fr.new_re;
		fr.old_im = fr.new_im;
		fr.re_sqr = fr.old_re * fr.old_re;
		fr.im_sqr = fr.old_im * fr.old_im;
		fr.new_re = (fr.re_sqr - (fr.im_sqr * 3)) * fr.old_re + fr.p_re;
		fr.new_im = ((fr.re_sqr * 3) - fr.im_sqr) * fr.old_im + fr.p_im;
		fr.i++;
	}
	ft_color(img_data, fr, param->max_iterations);
}

void	ft_celtic_heart(char *img_data, t_param *param, t_fr fr)
{
	fr.p_re = 1.5 * (fr.x - (double)fr.width / 2)
			/ (0.5 * param->zoom * fr.width) + param->move_x;
	fr.p_im = (fr.y - (double)HEIGHT / 2)
			/ (0.5 * param->zoom * HEIGHT) + param->move_y;
	fr.new_re = 0;
	fr.new_im = 0;
	fr.old_re = 0;
	fr.old_im = 0;
	fr.i = 0;
	while (fr.i < param->max_iterations &&
	(fr.new_re * fr.new_re + fr.new_im * fr.new_im) < 4)
	{
		fr.old_re = fr.new_re;
		fr.old_im = fr.new_im;
		fr.re_sqr = fr.old_re * fr.old_re;
		fr.im_sqr = fr.old_im * fr.old_im;
		fr.new_re = fabs(fr.re_sqr - fr.im_sqr) + fr.p_re;
		fr.new_im = fabs(fr.old_re) * fr.old_im * 2 + fr.p_im;
		fr.i++;
	}
	ft_color(img_data, fr, param->max_iterations);
}
