/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:00:40 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/22 11:34:46 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MLX_H
# define TEST_MLX_H

# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/libft_mandatory/includes/libft.h"
# include "../mlx_opengl/mlx.h"
# include "stdlib.h"
# include <math.h>

# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define GREEN 0x0000FF00
# define RED 0x00FF0000
# define BLACK 0x00000000
# define WWIDTH 800
# define MIDWIDTH WWIDTH / 2
# define WHEIGHT 800
# define MIDHEIGHT WHEIGHT / 2

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
	int		color;
}			t_point;

typedef struct s_repere
{
	double	width_min;
	double	width_max;
	double	height_min;
	double	height_max;
	double 	zoom;
	void	*mlx;
	void	*win;
	t_point	center;
	t_img	img;
}			t_repere;

//================== UTILS ====================
int			handle_key(int keycode, t_repere *coords);
int			close_win(t_repere *coords);
int			my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			is_approx(int x, int y);
int			handle_mouse(int x, int y, void *is_enter);
int			handle_zoom(int button, int x, int y, t_repere *coords);
double		round_value(double value, int roundness);

//=============================================

//================== UTILS ====================
void		main_draw(t_repere *coords);
//=============================================

//================== SHAPES ===================
int			print_rectangle(t_img *img, int width, int height, int x, int y,
				int color);
int			print_square(t_img *img, int side, int x, int y, int color);
int			print_triangle(t_img *img, int side, int x, int y, int color);
int			print_circle(t_img *img, int r, int x, int y, int color);
//=============================================

#endif