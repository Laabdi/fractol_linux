/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:06:06 by moaregra          #+#    #+#             */
/*   Updated: 2024/06/11 06:36:45 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	int	offset;

	offset = (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->addr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->real = fractal->julia_x;
		c->imag = fractal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->imag = z->imag;
	}
}

void	handle_pixels(t_fractal *fractol, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			color;
	int			i;

	z.real = getscaledvalue(x, 0, WIDTH, -2, 2 * fractol->zoom)
		+ fractol->shift_x;
	z.imag = getscaledvalue(y, 0, HEIGHT, -2, 2 * fractol->zoom)
		+ fractol->shift_y;
	mandel_vs_julia(&z, &c, fractol);
	i = 0;
	while (i <= fractol->iterations_defintion)
	{
		z = sum_comp(square_comp(z), c);
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
		{
			color = getscaledvalue(i, 0, fractol->iterations_defintion,
					0x000000, 0xFF0000);
			my_mlx_pixel_put(&fractol->image, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractol->image, x, y, 0xFFFF00);
}

void	render(t_fractal *fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			handle_pixels(fractol, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image.img,
		0, 0);
}
