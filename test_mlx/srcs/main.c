/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:25:22 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/22 11:36:45 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_mlx.h"

void	init_coords(t_repere *coords, int color)
{
	coords->height_max = 10.0;
	coords->height_min = -10.0;
	coords->width_max = 10.0;
	coords->width_min = -10.0;
	coords->center.x = 0.0;
	coords->center.y = 0.0;
	coords->zoom = 1.0;
	coords->center.color = color;
	coords->mlx = mlx_init();
	coords->win = mlx_new_window(coords->mlx, WWIDTH, WHEIGHT,
			"test for learning");
	coords->img.img = mlx_new_image(coords->mlx, WWIDTH, WHEIGHT);
	coords->img.addr = mlx_get_data_addr(coords->img.img,
			&coords->img.bits_per_pixel, &coords->img.line_length,
			&coords->img.endian);
}

int	main(void)
{
	t_repere	coords;

	// image de test
	init_coords(&coords, WHITE);
	main_draw(&coords);
	// my_mlx_pixel_put(&coords->img, 100, 100, RED);
	// gestion du quittage
	mlx_hook(coords.win, ON_DESTROY, 0L, close_win, &coords);
	mlx_hook(coords.win, ON_KEYDOWN, 0L, handle_key, &coords);
	mlx_hook(coords.win, ON_MOUSEDOWN, 0L, handle_zoom, &coords);
	// is_enter = mlx_hook(coords.win, ON_MOUSEMOVE, 0L, handle_mouse,
			//&is_enter);
	mlx_loop(coords.mlx);
	return (0);
}

// liste des choses a faire

// -> meilleurs qualite de pixels
// -> zoom
// -> déplacement de la fenêtres avec les flèches