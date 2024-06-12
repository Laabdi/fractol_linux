/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 02:57:26 by moaregra          #+#    #+#             */
/*   Updated: 2024/06/12 02:36:44 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./minilibx-linux/mlx.h"
# include <X11/Xlib.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define DESTROY_NOTIFY 29
# define XK_ESCAPE 0xff1b

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_fractal
{
	void	*mlx;
	char	*name;
	void	*window;
	t_img	image;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		iterations_defintion;
}			t_fractal;

t_complex	sum_comp(t_complex z, t_complex c);
t_complex	square_comp(t_complex z);
double		ft_atodbl(char *s);
double		getscaledvalue(double value, double sourceRangeMin,
				double sourceRangeMax, double targetRangeMin,
				double targetRangeMax);
int			close_window(t_fractal *fractol);
int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr(char *s);
void		render(t_fractal *fractol);
int			events_handler(int keysym, t_fractal *fractol);
void		mlx_key_gere(t_fractal *fractol);
void		cleanup_and_exit(t_fractal *fractol);

#endif