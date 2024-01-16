/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:05:10 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 12:04:01 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief Fonction d'interpolation linéaire pour la couleur.
 *
 * @param t Paramètre d'interpolation.
 * @return int Couleur interpolée.
 */

int	linear_interpolation(double t, t_fractol *fractol)
{
	int	red;
	int	green;
	int	blue;

	if (t < 0)
		t = 0;
	if (t > 1)
		t = 1;
	red = ((fractol->color >> 16) & 0xFF) * t;
	green = ((fractol->color >> 8) & 0xFF) * t;
	blue = (fractol->color & 0xFF) * t;
	return ((red << 16) | (green << 8) | blue);
}

/**
* @brief Fonction pour déterminer la couleur d'un pixel à l'extérieur 
 *	de l'ensemble de Mandelbrot.
 * 
 * @param z Le point z après l'itération finale.
 * @param der La dérivée de z après l'itération finale.
 * @return int Couleur à appliquer au format 0x00RRGGBB.
 */
int	normal_color(t_complex z, t_complex der, t_fractol *fractol)
{
	t_complex	u;
	t_complex	v;
	double		t;
	double		angle;

	angle = 2.0 * ANGLE * M_PI / 360.0;
	exp_complex(angle, &v);
	u = divide_complex(z, der);
	u.x /= abs_complex(u);
	u.y /= abs_complex(u);
	t = dot_complex(&u, &v) + fractol->color_h;
	t = t / (1 + fractol->color_h);
	return (linear_interpolation(t, fractol));
}
