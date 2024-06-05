#include "fractol.h"

t_complex sum_comp(t_complex z, t_complex c) 
{
    t_complex result;
    result.real = z.real + c.real;
    result.imag = z.imag + c.imag;
    return result;
}

t_complex square_comp(t_complex z) 
{
    t_complex result;
    result.real = z.real * z.real - z.imag * z.imag;
    result.imag = 2 * z.real * z.imag;
    return result;
}
double getScaledValue(double value, double sourceRangeMin, double sourceRangeMax, double targetRangeMin, double targetRangeMax) 
{
    double targetRange = targetRangeMax - targetRangeMin;
    double sourceRange = sourceRangeMax - sourceRangeMin;
    return ((value - sourceRangeMin) * targetRange / sourceRange) + targetRangeMin;
}