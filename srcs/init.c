/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:14:03 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 12:32:08 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_handle(t_fractol *fractol)
{
	mlx_hook(fractol->win, ON_DESTROY, StructureNotifyMask, handle_close_win,
		fractol);
	mlx_hook(fractol->win, ON_KEYDOWN, KeyPressMask, handle_key, fractol);
	mlx_hook(fractol->win, ON_MOUSEDOWN, ButtonPressMask, handle_zoom, fractol);
}

void	init_data(t_fractol *fractol)
{
	fractol->zoom = 1.0;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->escape_value = ESCAPE_VALUE;
	fractol->max_iter = ITERATIONS_MAX;
	fractol->scale.x = MAPX_MAX - MAPX_MIN;
	fractol->scale.y = MAPY_MAX - MAPY_MIN;
	fractol->help = 0.0;
	fractol->zoom_iter = 0;
	fractol->color_h = 2;
	fractol->color = WHITE;
}

void	init_constant(t_fractol *fractol, t_complex *c, t_complex *z)
{
	if (fractol->is_julia)
	{
		c->x = fractol->j_x;
		c->y = fractol->j_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

/**
 * @brief init fractol struct
 * ->	check if all malloc is good
 * ->	set data to init value
 * @param fractol return the fractol well initialised
 */
void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		exit_program(MALLOC_ERROR, fractol);
	fractol->win = mlx_new_window(fractol->mlx, WWIDTH, WHEIGHT,
			"Fractol TOUKOUM");
	if (!fractol->win)
	{
		free(fractol->mlx);
		exit_program(MALLOC_ERROR, fractol);
	}
	fractol->img.img = mlx_new_image(fractol->mlx, WWIDTH, WHEIGHT);
	if (!fractol->img.img)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
		exit_program(MALLOC_ERROR, fractol);
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img,
			&fractol->img.bits_per_pixel, &fractol->img.line_length,
			&fractol->img.endian);
	init_data(fractol);
	init_handle(fractol);
}
