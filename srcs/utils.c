/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:14:35 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 12:27:39 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_input_correct(t_fractol *fractol, int argc, char **argv)
{
	fractol->is_mandel = 0;
	fractol->is_julia = 0;
	fractol->is_ship = 0;
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fractol->is_mandel = 1;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
		fractol->is_julia = 1;
	else if (argc == 2 && !ft_strncmp(argv[1], "burningship", 11))
		fractol->is_ship = 1;
	if (fractol->is_julia || fractol->is_mandel || fractol->is_ship)
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

int	is_escape(int escape_value, t_complex *complex)
{
	return ((complex->x * complex->x + complex->y * complex->y) > escape_value);
}
