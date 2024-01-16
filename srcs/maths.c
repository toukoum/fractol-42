/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:31:31 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 12:31:11 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief calcul the next complex number in the mandelbrot set
 *
 * 		=> z = z^2 + z
 *
 * @param complex
 * @return t_complex
 */

t_complex	next_complex(t_complex z, t_complex c, int is_ship)
{
	t_complex	result;

	result.x = z.x * z.x - z.y * z.y + c.x;
	result.y = 2 * z.x * z.y + c.y;
	if (is_ship)
	{
		if (result.x < 0)
			result.x *= -1;
		if (result.y < 0)
			result.y *= -1;
	}
	return (result);
}

double	round_v(double round, int decimal)
{
	return ((round * decimal) / decimal);
}

/**
 * @brief try to optimize calcul with Cardioid / bulb checking
 *
 * @param x coord
 * @param y
 * @return true if the point is in the set
 */
int	is_in_mandelbrot_set(double x, double y)
{
	double	p;
	double	q;

	p = sqrt((x - 0.25) * (x - 0.25) + y * y);
	if (x < p - 2 * p * p + 0.25)
		return (1);
	q = (x + 1) * (x + 1) + y * y;
	if (q <= 1.0 / 16.0)
		return (1);
	return (0);
}

t_complex	ft_map_complex(t_pixel *pixel, t_fractol *fractol)
{
	t_complex	map_complex;

	map_complex.x = ((pixel->x * fractol->scale.x) / WWIDTH + MAPX_MIN)
		* fractol->zoom + fractol->shift_x;
	map_complex.y = ((pixel->y * fractol->scale.y) / WHEIGHT + MAPY_MIN)
		* fractol->zoom + fractol->shift_y;
	return (map_complex);
}

double	ft_map(double unscaled_num, double new_min, double new_max,
		double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / (old_max) + new_min);
}
