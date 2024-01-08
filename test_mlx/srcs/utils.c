/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:57:19 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/22 11:35:51 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_mlx.h"

int	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
	return (0);
}

int	close_win(t_repere *coords)
{
	mlx_destroy_window(coords->mlx, coords->win);
	ft_printf("Window close successfully !");
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_key(int keycode, t_repere *coords)
{
	if (keycode == KEY_ESC)
		close_win(coords);
	else if (keycode == KEY_ARROW_LEFT)
	{
		coords->width_max -= 1;
		coords->width_min -= 1;
		coords->center.x += 1;
	}
	else if (keycode == KEY_ARROW_RIGHT)
	{
		coords->width_max += 1;
		coords->width_min += 1;
		coords->center.x -= 1;
	}
	else if (keycode == KEY_ARROW_TOP)
	{
		coords->height_max -= 1;
		coords->height_min -= 1;
		coords->center.y += 1;
	}
	else if (keycode == KEY_ARROW_BOT)
	{
		coords->height_max += 1;
		coords->height_min += 1;
		coords->center.y -= 1;
	}
	main_draw(coords);
	return (0);
}

int	handle_zoom(int button, int x, int y, t_repere *coords)
{
	(void)x;
	(void)y;
	if (button == 5)
	{
		coords->zoom *= 1.1;
		coords->height_max *= 0.9;
		coords->width_max *= 0.9;
		coords->height_min *= 0.9;
		coords->width_min *= 0.9;
	}
	else if (button == 4)
	{
		coords->zoom *= 0.9;
		coords->height_max *= 1.1;
		coords->width_max *= 1.1;
		coords->height_min *= 1.1;
		coords->width_min *= 1.1;
	}
	if (button == 4 || button == 5)
		main_draw(coords);
	return (0);
}

int	handle_mouse(int x, int y, void *is_enter)
{
	int	enter;

	enter = 0;
	(void)is_enter;
	if ((x >= 0 && x <= WWIDTH) && (y >= 0 && y <= WHEIGHT) && !enter)
	{
		ft_printf("Hello!");
		return (1);
	}
	else
	{
		ft_printf("Bye!");
		return (0);
	}
}

int	is_approx(int x, int y)
{
	return (abs(x - y) <= 400);
}
