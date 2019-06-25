/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:24:19 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/24 20:16:43 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_putendl("Usage: ./fractol [Julia, Mandelbrot, Burningship, "
				"Perpendicular_Celtic, Cubic_Mandelbar, Mandelbrot_4_Order, "
				"Cubic_Mandelbrot, Celtic_Heart]");
		exit(1);
	}
	else if (error == 2)
	{
		ft_putendl("Memory allocation error");
		exit(2);
	}
}
