/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:24:23 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 15:59:56 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	malloc_error(void)
{
	perror("Malloc Error !");
	exit(EXIT_FAILURE);
}

/**
 * @brief sucess exit, free all the memory properly
 *
 * @param fractol
 */
static void	free_fractol(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	ft_printf("Program quit successfully !");
	exit(EXIT_SUCCESS);
}

/**
 * @brief main funcion for quit program
 *
 * @param code the code of the exit cause
 * @param fractol main struct
 */
void	exit_program(int code, t_fractol *fractol)
{
	if (code == MALLOC_ERROR)
		malloc_error();
	else if (code == SUCESS)
		free_fractol(fractol);
	else if (code == INPUT_ERROR)
	{
		ft_printf("\033[1;31mError, please enter valid arguments.\033[0m\n\n"
			"  => \033[1;34m./fractol <mandelbrot>\033[0m\n"
			"  => \033[1;34m./fractol <julia> <Im> <Re>\033[0m\n"
			"  => \033[1;34m./fractol <burningship>\033[0m\n\n");
		exit(1);
	}
}
