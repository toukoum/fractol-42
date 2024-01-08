/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:00:40 by rgiraud           #+#    #+#             */
/*   Updated: 2024/01/05 16:39:05 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/libft_mandatory/includes/libft.h"
# include "../mlx-opengl/mlx.h"
# include "stdlib.h"
# include <math.h>
# include <mlx.h>


//--------------------------------------------
//=================== DEFINE =================
//--------------------------------------------

// =========== COLOR ===========
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLACK 0x00000000
// =============================

// =========== SIZE ============
# define WWIDTH 800
# define MIDWIDTH WWIDTH / 2
# define WHEIGHT 800
# define MIDHEIGHT WHEIGHT / 2
// =============================

// ============ KEY ============
# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_E 14
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ARROW_TOP 126
#  define KEY_ARROW_BOT 125
#  define KEY_ARROW_LEFT 123
#  define KEY_ARROW_RIGHT 124
# elif __linux__
#  define KEY_ESC 65307
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_E 101
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ARROW_TOP 65362
#  define KEY_ARROW_BOT 65364
#  define KEY_ARROW_LEFT 65361
#  define KEY_ARROW_RIGHT 65363
# endif
// =============================

// ========= EXIT CODE ========
# define MALLOC_ERROR 0
# define SUCESS 1

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
	t_point	center;
	double	width_min;
	double	width_max;
	double	height_min;
	double	height_max;
}			t_fractol;

//--------------------------------------------
//================= FUNCTIONS ================
//--------------------------------------------

// ============ exit =============
void		exit_program(int code, t_fractol *fractol);
// ===============================

// ============ init =============
void		init_fractol(t_fractol *fractol);

// ===============================

// ============ util =============
int			my_mlx_pixel_put(t_img *img, int x, int y, int color);

// ===============================

// ============ render =============
void		render(t_fractol *fractol);
// ===============================

// ============ events =============
int			handle_zoom(int button, int x, int y, t_fractol *fractol);
int			handle_key(int keycode, t_fractol *fractol);
int			handle_close_win(t_fractol *fractol);
// ===============================

#endif