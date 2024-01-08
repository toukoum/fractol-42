/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:24:23 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/05 16:24:49 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


static void malloc_error()
{
	perror("Malloc Error !");
	exit(EXIT_FAILURE);
}
static void free_fractol(t_fractol *fractol)
{
	//mlx_destroy_image(fractol->mlx, fractol->img.img);
	if (fractol.wi)
	mlx_destroy_window(fractol->mlx, fractol->win);
	free(fractol->mlx);
	//(void)fractol;
	ft_printf("Programm quit successfully !");
	exit(EXIT_SUCCESS);
}

void exit_program(int code, t_fractol *fractol)
{
	if (code == MALLOC_ERROR)
		malloc_error();
	else if (code == SUCESS)
		free_fractol(fractol);
}