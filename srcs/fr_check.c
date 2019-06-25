/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 16:23:53 by sdatskov          #+#    #+#             */
/*   Updated: 2019/06/24 20:15:22 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_check(char *name)
{
	if (ft_strcmp(name, "Julia") == 0)
		return (1);
	else if (ft_strcmp(name, "Mandelbrot") == 0)
		return (2);
	else if (ft_strcmp(name, "Burningship") == 0)
		return (3);
	else if (ft_strcmp(name, "Perpendicular_Celtic") == 0)
		return (4);
	else if (ft_strcmp(name, "Cubic_Mandelbar") == 0)
		return (5);
	else if (ft_strcmp(name, "Mandelbrot_4_Order") == 0)
		return (6);
	else if (ft_strcmp(name, "Cubic_Mandelbrot") == 0)
		return (7);
	else if (ft_strcmp(name, "Celtic_Heart") == 0)
		return (8);
	else
		return (0);
}
