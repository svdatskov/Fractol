/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:24:02 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/23 20:35:20 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color(char *img_data, t_fr fr, int max)
{
	double	modulus;
	double	mu;
	double	t;
	t_rgb	rgb;

	modulus = sqrt(fr.new_re * fr.new_re + fr.new_im * fr.new_im);
	mu = (double)fr.i - (log(log(modulus))) / log(2.0);
	t = mu / max;
	rgb.r = 9 * (1 - t) * t * t * t * 255;
	rgb.g = 15 * (1 - t) * (1 - t) * t * t * 255;
	rgb.b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	if (rgb.r >= 0 && rgb.r <= 255 && rgb.b >= 0 &&
	rgb.b <= 255 && rgb.g >= 0 && rgb.g <= 255)
	{
		img_data[fr.x * 4 + 4 * IMG_WIDTH * fr.y] = (unsigned char)rgb.r;
		img_data[fr.x * 4 + 4 * IMG_WIDTH * fr.y + 1] = (unsigned char)rgb.g;
		img_data[fr.x * 4 + 4 * IMG_WIDTH * fr.y + 2] = (unsigned char)rgb.b;
	}
}
