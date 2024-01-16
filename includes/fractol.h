/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:00:40 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/16 16:23:08 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/libft_mandatory/includes/libft.h"
# include "../mlx-linux/mlx.h"
# include "stdlib.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>

//----------------------------------------------
//=================== DEFINE ===================
//----------------------------------------------

// =========== COLOR ===========
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLACK 0x00000000

# define CYAN 0x0000FFFF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define ORANGE 0x00FFA500
# define PINK 0x00FFC0CB
# define LIME 0x0000FF80
// =============================

// =========== SIZE ============
# define WWIDTH 800
# define MIDWIDTH 400
# define WHEIGHT 800
# define MIDHEIGHT 400
# define MAPY_MIN -2
# define MAPY_MAX 2
# define MAPX_MIN -2
# define MAPX_MAX 2
// =============================

// ========= EXIT CODE =========
# define MALLOC_ERROR 0
# define SUCESS 1
# define INPUT_ERROR 2
// =============================

// ========== DIVERS ===========
# define ITERATIONS_MAX 40
# define ESCAPE_VALUE 4
# define SHIFTV 0.5
# define H2 5
# define ANGLE 1.5
# define RED_SHIFT 0x0F0000
# define GREEN_SHIFT 0x002000
# define BLUE_SHIFT 0x00000A
// =============================

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

//--------------------------------------------
//================= STRUCTURES ===============
//--------------------------------------------

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_pixel
{
	double	x;
	double	y;
}			t_pixel;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_point	scale;
	double	zoom;
	double	shift_x;
	double	shift_y;
	int		max_iter;
	int		escape_value;
	int		is_mandel;
	int		is_julia;
	int		is_ship;
	double	j_x;
	double	j_y;
	double	mod_z;
	int		help;
	int		zoom_iter;
	int		color;
	double	color_h;
}			t_fractol;

//--------------------------------------------
//================= FUNCTIONS ================
//--------------------------------------------

// ============ exit =============
void		exit_program(int code, t_fractol *fractol);
// ===============================

// ============ init =============
void		init_fractol(t_fractol *fractol);
void		init_constant(t_fractol *fractol, t_complex *c, t_complex *z);
void		init_data(t_fractol *fractol);

// ===============================

// ============ util =============
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_complex	next_complex(t_complex z, t_complex c, int is_ship);
double		atod(char *str, int *error, double len_dec);
double		round_v(double round, int decimal);
double		ft_map(double unscaled_num, double new_min, double new_max,
				double old_max);
int			is_escape(int escape_value, t_complex *complex);
int			is_in_mandelbrot_set(double x, double y);
t_complex	ft_map_complex(t_pixel *pixel, t_fractol *fractol);
void		handle_pixel(t_fractol *fractol, t_pixel *pixel);
int			is_input_correct(t_fractol *fractol, int argc, char **argv);
void		display_help(t_fractol *fractol);

// ===============================

// ============ render =============
int			render(t_fractol *fractol);
// ===============================

// ============ color =============
int			normal_color(t_complex z, t_complex der, t_fractol *fractol);
t_complex	divide_complex(t_complex numerator, t_complex denominator);
t_complex	conjugate(t_complex a);
void		exp_complex(double angle, t_complex *result);
double		dot_complex(t_complex *a, t_complex *b);
double		abs_complex(t_complex complex);
// ===============================

// ============ events =============
int			handle_zoom(int button, int x, int y, t_fractol *fractol);
int			handle_key(int keycode, t_fractol *fractol);
int			handle_close_win(t_fractol *fractol);
// ===============================

#endif