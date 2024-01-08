/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:19:48 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/22 22:31:05 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int handle_close_win(t_fractol *fractol)
{
	exit_program(SUCESS, fractol);
	return (0);
}

int handle_key(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
		exit_program(SUCESS, fractol);
	return (0);
}

int handle_zoom(int button, int x, int y, t_fractol *fractol)
{
	(void)fractol;
	ft_printf(" mouse: %d (%d, %d)\n", button, x, y);
	return (0);
}
