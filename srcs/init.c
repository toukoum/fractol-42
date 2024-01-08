/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:14:03 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/22 22:32:03 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void init_handle(t_fractol *fractol)
{
	mlx_hook(fractol->win, ON_DESTROY, 0L, handle_close_win, &fractol);
	mlx_hook(fractol->win, ON_KEYDOWN, 0L, handle_key, &fractol);
	mlx_hook(fractol->win, ON_MOUSEDOWN, 0L, handle_zoom, &fractol);
}

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit_program(MALLOC_ERROR, fractol);
	fractol->win = mlx_new_window(fractol->mlx, WWIDTH, WHEIGHT, "Fractol TOUKOUM");
	if (!fractol->win)
	{
		free(fractol->mlx);
		exit_program(MALLOC_ERROR, fractol);
	}
	fractol->img.img = mlx_new_image(fractol->mlx, WWIDTH, WHEIGHT);
	if (!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit_program(MALLOC_ERROR, fractol);
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	fractol->center.x = 0.0;
	fractol->center.y = 0.0;
	fractol->height_max = 2;
	fractol->height_min = -2;
	fractol->width_max = 2;
	fractol->width_min = -2;
	init_handle(fractol);
}
