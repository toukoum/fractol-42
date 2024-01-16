/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:25:22 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 16:01:04 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/**
 * @brief atod for a and ib param of julia
 * if atod = -1 => -0.
 * if error = 1 => overflow or underflow
 *
 * @param fractol
 * @param argv
 * @param error ptr to error status for over/under flow
 */
static void	init_julia(t_fractol *fractol, char **argv, int *error)
{
	double	len_dec;

	len_dec = 1.0;
	fractol->j_x = atod(argv[2], error, len_dec);
	if (*error == -1)
		fractol->j_x *= -1;
	if (*error == 1)
		exit_program(INPUT_ERROR, fractol);
	*error = 0;
	fractol->j_y = atod(argv[3], error, len_dec);
	if (*error == -1)
		fractol->j_x *= -1;
	if (*error == 1)
		exit_program(INPUT_ERROR, fractol);
}

/**
 * @brief this project accept either 2 arguments either 4 maximum
 *
 *  => ./fractol mandelbrot
 *  => ./fractol julia Re Im
 *
 *  1- Init of Struct fractol and hook
 *  2- Display fractal
 * 	3- Redisplay fractal in case of hooking (zoom, arrow key)
 * 	4- Loop
 *
 * @param argc
 * @param argv
 * @return int
 */
int	main(int argc, char **argv)
{
	t_fractol	fractol;
	int			error;

	error = 0;
	if (is_input_correct(&fractol, argc, argv))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
			init_julia(&fractol, argv, &error);
		init_fractol(&fractol);
		render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		exit_program(INPUT_ERROR, &fractol);
	return (0);
}
