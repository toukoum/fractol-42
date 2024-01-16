/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:59:18 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 16:13:17 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	display_iterations(t_fractol *fractol, int x, int *y,
		int line_height)
{
	char	*temp_str;

	temp_str = ft_itoa(fractol->max_iter);
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"Iterations: ");
	mlx_string_put(fractol->mlx, fractol->win, x + 80, *y, 0XFFFFFF
		- fractol->color, temp_str);
	*y += line_height;
	free(temp_str);
}

static void	init_zoom_shift(char *zoom, char *shift)
{
	zoom[0] = 'Z';
	zoom[1] = 'o';
	zoom[2] = 'o';
	zoom[3] = 'm';
	zoom[4] = ':';
	zoom[5] = ' ';
	zoom[6] = '\0';
	shift[0] = 'S';
	shift[1] = 'h';
	shift[2] = 'i';
	shift[3] = 'f';
	shift[4] = 't';
	shift[5] = ' ';
	shift[6] = 'X';
	shift[7] = ':';
	shift[8] = ' ';
	shift[9] = '\0';
}

static void	display_zoom_shift(t_fractol *fractol, int x, int *y,
		int line_height)
{
	char	zoom_str[50];
	char	shift_str[100];
	char	*temp_str;

	init_zoom_shift(zoom_str, shift_str);
	temp_str = ft_itoa((int)(-fractol->zoom_iter));
	ft_strlcat(zoom_str, temp_str, sizeof(zoom_str));
	free(temp_str);
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		zoom_str);
	*y += line_height;
	temp_str = ft_itoa((int)(fractol->shift_x * 10));
	ft_strlcat(shift_str, temp_str, sizeof(shift_str));
	free(temp_str);
	temp_str = ft_itoa((int)(-fractol->shift_y * 10));
	ft_strlcat(shift_str, ", Shift Y: ", sizeof(shift_str));
	ft_strlcat(shift_str, temp_str, sizeof(shift_str));
	free(temp_str);
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		shift_str);
	*y += line_height;
}

static void	display_controls(int x, int *y, int line_height, t_fractol *fractol)
{
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"Arrows: Move");
	*y += line_height;
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"Plus: Increase precision");
	*y += line_height;
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"Minus: Decrease precision");
	*y += line_height;
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"1 / 2: More or less BLUE");
	*y += line_height;
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"3 / 4: More or less PINK");
	*y += line_height;
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"5 / 6: More or less YELLOW");
	*y += line_height;
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"7 / 8: Shadow height");
	*y += line_height;
	mlx_string_put(fractol->mlx, fractol->win, x, *y, 0XFFFFFF - fractol->color,
		"r : reset");
	*y += line_height;
}

/**
 * @brief for display relevant informations
 * 			le nombre d'iterations pour la precision
 * 			le niveau de zoom
 * 			les coordonne x et y
 * 			l'aide des touche arrow for move, plus for more precision,
				minus for less
 *
 * @param fractol
 */
void	display_help(t_fractol *fractol)
{
	int	x;
	int	y;
	int	line_height;

	line_height = 20;
	y = 40;
	x = 20;
	if (fractol->is_mandel)
		mlx_string_put(fractol->mlx, fractol->win, MIDWIDTH - 65, 30,
			fractol->color, "== MANDELBROT SET ==");
	if (fractol->is_julia)
		mlx_string_put(fractol->mlx, fractol->win, MIDWIDTH - 55, 30,
			fractol->color, "== JULIA SET ==");
	if (fractol->is_ship)
		mlx_string_put(fractol->mlx, fractol->win, MIDWIDTH - 70, 30,
			fractol->color, "== BURNING SHIP SET ==");
	display_iterations(fractol, x, &y, line_height);
	display_zoom_shift(fractol, x, &y, line_height);
	display_controls(x, &y, line_height, fractol);
}
