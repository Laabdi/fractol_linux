/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 03:01:30 by moaregra          #+#    #+#             */
/*   Updated: 2024/06/11 03:04:46 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum_comp(t_complex z, t_complex c)
{
	t_complex	result;

	result.real = z.real + c.real;
	result.imag = z.imag + c.imag;
	return (result);
}

t_complex	square_comp(t_complex z)
{
	t_complex	result;

	result.real = z.real * z.real - z.imag * z.imag;
	result.imag = 2 * z.real * z.imag;
	return (result);
}

double	getscaledvalue(double value, double sourcerangemin,
		double sourcerangemax, double targetrangemin, double targetrangemax)
{
	double	sourcerange;
	double	targetrange;

	targetrange = targetrangemax - targetrangemin;
	sourcerange = sourcerangemax - sourcerangemin;
	return (((value - sourcerangemin) * targetrange / sourcerange)
		+ targetrangemin);
}
