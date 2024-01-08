/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:22:57 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/04 16:48:57 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_mlx.h"

double round_value(double value, int roundness) {
    return round(value * roundness) / roundness;
}

t_point	ft_remap(t_point *pixel, t_repere *coords)
{
	t_point	map_point;

	map_point.x = (((coords->width_max - coords->width_min) * (pixel->x)) / (WWIDTH)) + coords->width_min;
	map_point.y = -((((coords->height_max - coords->height_min) * (pixel->y)) / (WWIDTH)) + coords->height_min);
	map_point.x = round_value(map_point.x, 10 + coords->zoom);
	map_point.y = round_value(map_point.y, 10 + coords->zoom);
	return (map_point);
}

void	black_image(t_repere *coords)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WWIDTH)
	{
		j = -1;
		while (++j < WHEIGHT)
			my_mlx_pixel_put(&coords->img, i, j, BLACK);
	}
}

static void	handle_pixel(t_repere *coords, t_point *pixel)
{
	t_point	point;

	point = ft_remap(pixel, coords);
	
	//point = (ft_remap(pixel, coords) + shift_hor + shift_ver) * zoom;

	
	if ((point.y == 1 && (point.x >= -1 && point.x <= 1)) || (point.y == -1
			&& (point.x >= -1 && point.x <= 1)) || (point.x == 1 && (point.y >=
				-1 && point.y <= 1)) || (point.x == -1 && (point.y >= -1
				&& point.y <= 1)))
		my_mlx_pixel_put(&coords->img, pixel->x, pixel->y, RED);
	else if (point.y == 0 || point.x == 0)
		my_mlx_pixel_put(&coords->img, pixel->x, pixel->y, WHITE);
		
}

void	main_draw(t_repere *coords)
{
	printf("ETA: center(%f, %f) ; height(%f, %f) ; width(%f, %f)\n", coords->center.x, coords->center.y, coords->height_min, coords->height_max, coords->width_min, coords->width_max);
	black_image(coords);
	int i;
	int j;
	t_point point;
	i = 0;
	while (i < WHEIGHT)
	{
		j = 0;
		while (j < WWIDTH)
		{
			point.x = j;
			point.y = i;
			handle_pixel(coords, &point);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(coords->mlx, coords->win, coords->img.img, 0, 0);
}