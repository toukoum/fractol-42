/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:19:48 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 16:17:47 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_close_win(t_fractol *fractol)
{
	exit_program(SUCESS, fractol);
	return (0);
}

static void	color_handle(t_fractol *fractol, int keycode)
{
	if (keycode == XK_1 && (fractol->color & 0xFF0000) < 0xFF0000)
		fractol->color += RED_SHIFT;
	else if (keycode == XK_2 && (fractol->color & 0xFF0000) > 0x000000)
		fractol->color -= RED_SHIFT;
	if (keycode == XK_3 && (fractol->color & 0x00FF00) < 0x00FF00)
		fractol->color += GREEN_SHIFT;
	else if (keycode == XK_4 && (fractol->color & 0x00FF00) > 0x000000)
		fractol->color -= GREEN_SHIFT;
	if (keycode == XK_5 && (fractol->color & 0x0000FF) < 0x0000FF)
		fractol->color += BLUE_SHIFT;
	else if (keycode == XK_6 && (fractol->color & 0x0000FF) > 0x000000)
		fractol->color -= BLUE_SHIFT;
}

void	shift_handle(int keycode, t_fractol *fractol)
{
	double	shift;

	shift = round_v(SHIFTV * (fractol->zoom * 2), 10);
	if (keycode == XK_Left)
		fractol->shift_x -= shift;
	else if (keycode == XK_Right)
		fractol->shift_x += shift;
	else if (keycode == XK_Up)
		fractol->shift_y -= shift;
	else if (keycode == XK_Down)
		fractol->shift_y += shift;
	else if (keycode == XK_equal)
		fractol->max_iter += 5;
	else if (keycode == XK_minus)
		fractol->max_iter -= 5;
}

int	handle_key(int keycode, t_fractol *fractol)
{
	if (keycode == XK_Escape)
		exit_program(SUCESS, fractol);
	else if (keycode == XK_7)
		fractol->color_h -= 0.1;
	else if (keycode == XK_8)
		fractol->color_h += 0.1;
	else if (keycode == XK_r)
		init_data(fractol);
	else if (keycode == XK_Left || keycode == XK_Right || keycode == XK_Up
		|| keycode == XK_Down || keycode == XK_equal || keycode == XK_minus)
		shift_handle(keycode, fractol);
	else if (keycode == XK_h && fractol->help)
		fractol->help = 0;
	else if (keycode == XK_h && !fractol->help)
		fractol->help = 1;
	else if (keycode == XK_1 || keycode == XK_2 || keycode == XK_3
		|| keycode == XK_4 || keycode == XK_5 || keycode == XK_6)
		color_handle(fractol, keycode);
	return (render(fractol));
}

int	handle_zoom(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_factor;
	t_point	mouse_map;

	mouse_map.x = ft_map(x, -MIDWIDTH, MIDWIDTH, WWIDTH);
	mouse_map.y = ft_map(y, -MIDHEIGHT, MIDHEIGHT, WHEIGHT);
	zoom_factor = 1;
	if (button == 5)
	{
		zoom_factor = 1.5;
		fractol->zoom_iter++;
		fractol->zoom *= zoom_factor;
	}
	else if (button == 4)
	{
		fractol->zoom_iter--;
		zoom_factor = 0.7;
		fractol->zoom *= zoom_factor;
		fractol->shift_x += (mouse_map.x / (WWIDTH / 2)) * fractol->zoom;
		fractol->shift_y += (mouse_map.y / (WWIDTH / 2)) * fractol->zoom;
	}
	if (fractol->max_iter < ITERATIONS_MAX)
		fractol->max_iter += fractol->zoom;
	render(fractol);
	return (0);
}
