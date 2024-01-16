/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:45:11 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 11:48:30 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	abs_complex(t_complex complex)
{
	return (sqrt(complex.x * complex.x + complex.y * complex.y));
}

double	dot_complex(t_complex *a, t_complex *b)
{
	return (a->x * b->x + a->y * b->y);
}

void	exp_complex(double angle, t_complex *result)
{
	double	magnitude;

	magnitude = exp(angle);
	result->x = magnitude * cos(angle);
	result->y = magnitude * sin(angle);
}

/**
 * @brief Calcule le conjugué d'un nombre complexe.
 *
 * @param a Le nombre complexe.
 * @return t_complex Le conjugué du nombre complexe.
 */
t_complex	conjugate(t_complex a)
{
	t_complex	result;

	result.x = a.x;
	result.y = -a.y;
	return (result);
}

/**
 * @brief Divise deux nombres complexes.
 *
 * @param numerator Le numérateur (z).
 * @param denominator Le dénominateur (w).
 * @return t_complex Le résultat de la division.
 */
t_complex	divide_complex(t_complex numerator, t_complex denominator)
{
	t_complex	result;
	t_complex	denom_conjugate;
	t_complex	num_mult;
	double		denom_mult;

	denom_conjugate = conjugate(denominator);
	num_mult = (t_complex){numerator.x * denom_conjugate.x - numerator.y
		* denom_conjugate.y, numerator.x * denom_conjugate.y + numerator.y
		* denom_conjugate.x};
	denom_mult = denominator.x * denominator.x + denominator.y * denominator.y;
	result.x = num_mult.x / denom_mult;
	result.y = num_mult.y / denom_mult;
	return (result);
}
