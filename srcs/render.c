/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:05:32 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/22 22:29:42 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	render(t_fractol *fractol)
{
	
	for (int i = 0; i < WWIDTH; i++)
	{
		my_mlx_pixel_put(&fractol->img, i, MIDHEIGHT, GREEN);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}