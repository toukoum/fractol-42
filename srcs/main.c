/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:25:22 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/22 22:33:35 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		init_fractol(&fractol);
		render(&fractol);
		mlx_loop(fractol.mlx);
	}
	else
		ft_printf("Error, please enter valid arguments.\n\n  => ./fractol <mandelbrot>\n  => ./fractol <julia> <Im> <Re>\n\n");
	return (0);
}
