/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:05:32 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 12:31:21 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief
 * 		=> for each pixel, calcul if in mandelbrot set, if yes,
			draw with specific color
 * 		=> this function must be optimize
 *
 *  fractol->mod_z = module of z
 * @param fractol
 * @param pixel the pixel to calcul if in the set
 */
void	handle_pixel(t_fractol *fractol, t_pixel *pixel)
{
	t_complex	constant;
	t_complex	z;
	t_complex	der;
	int			i;

	i = -1;
	der = (t_complex){1.0, 0.0};
	z = ft_map_complex(pixel, fractol);
	init_constant(fractol, &constant, &z);
	if (is_in_mandelbrot_set(z.x, z.y) && fractol->is_mandel)
		return (my_mlx_pixel_put(&fractol->img, pixel->x, pixel->y, BLACK));
	while (++i < fractol->max_iter)
	{
		fractol->mod_z = z.x * z.x + z.y * z.y;
		if (fractol->mod_z > fractol->escape_value)
		{
			my_mlx_pixel_put(&fractol->img, pixel->x, pixel->y, normal_color(z,
					der, fractol));
			return ;
		}
		der = (t_complex){2 * z.x * der.x - 2 * z.y * der.y, 2 * z.x * der.y + 2
			* z.y * der.x};
		z = next_complex(z, constant, fractol->is_ship);
	}
	my_mlx_pixel_put(&fractol->img, pixel->x, pixel->y, BLACK);
}

/**
 * @brief for each pixel, handle it for determine which color apply
 *
 * @param fractol
 */
int	render(t_fractol *fractol)
{
	t_pixel	pixel;

	pixel.x = 0;
	pixel.y = 0;
	while (pixel.y < WHEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WWIDTH)
		{
			handle_pixel(fractol, &pixel);
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	if (fractol->help)
		display_help(fractol);
	else
		mlx_string_put(fractol->mlx, fractol->win, 20, 30, 0XFFFFFF
			- fractol->color, "Help: h");
	return (0);
}
