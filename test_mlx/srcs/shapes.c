/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:51:01 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/21 10:23:29 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_mlx.h"

int print_rectangle(t_img *img, int width, int height, int x, int y, int color)
{
	//diplays a rectangle of width x and height y
	int i;

	i = 0;
	while (i < width)
	{
		my_mlx_pixel_put(img, x + i, y, color);
		my_mlx_pixel_put(img, x + i, y + height, color);
		i++;
	}
	i = 0;
	while (i < height)
	{
		my_mlx_pixel_put(img, x, y + i, color);
		my_mlx_pixel_put(img, x + width, y + i, color);
		i++;
	}
	return (0);
}

int print_square(t_img *img, int side, int x, int y, int color)
{
	//diplays a square of width x
	int i;

	i = 0;	
	while (i < side)
	{
		my_mlx_pixel_put(img, x + i, y, color);
		my_mlx_pixel_put(img, x + i, y + side, color);
		my_mlx_pixel_put(img, x, y + i, color);
		my_mlx_pixel_put(img, x + side, y + i, color);
		i++;
	}
	return (0);
}

int print_triangle(t_img *img, int side, int x, int y, int color)
{
	//diplays a triangle of side x
	int i;

	i = 0;	
	while (i < side)
	{
		my_mlx_pixel_put(img, x + i, y + side, color);
		if (i < side / 2)
			my_mlx_pixel_put(img, x + i, side + y - i, color);
		else
			my_mlx_pixel_put(img, x + i, side / 2 + y + (i - side / 2), color);
		i++;
	}
	return (0);
}


int print_circle(t_img *img, int r, int x, int y, int color)
{
	//diplays a circle of radius r
	int a;
	int b;

	a = x - r;
	while (a <= x + r)
	{
		b = y - r;
		while (b <= y + r)
		{
			if (is_approx((a - x) * (a - x) + (b - y) * (b - y), r * r))
				my_mlx_pixel_put(img, a, b, color);
			b ++;
		}
		a++;
	}
	return (0);
}