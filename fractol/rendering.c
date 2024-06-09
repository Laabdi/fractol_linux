
#include "fractol.h" // Include other necessary header files if needed

void my_mlx_pixel_put(t_img *image, int x, int y, int color) 
{
    int offset;

    offset = (y * image->line_length + x * (image->bits_per_pixel / 8));
    *(unsigned int*)(image->addr + offset) = color;
}

void handle_pixels(t_fractal *fractol, int x, int y) 
{
    t_complex z;
    t_complex c;

    z.real = 0;
    z.imag = 0;

    int color;

    c.real = getScaledValue(x, 0, WIDTH, -2, 2 * fractol->zoom) + fractol->shift_x;
    c.imag = getScaledValue(y, 0, HEIGHT, -2, 2* fractol->zoom) + fractol->shift_y;

    int i = 0;
    while (i <= fractol->iterations_defintion) 
    {
        z = sum_comp(square_comp(z), c);
        if ((z.real * z.real) + (z.imag * z.imag) > 4) 
        {
            color = getScaledValue(i, 0, fractol->iterations_defintion, 0x000000, 0xFF0000);
            my_mlx_pixel_put(&fractol->image, x, y, color);
            return;
        }
        i++;
    }
    my_mlx_pixel_put(&fractol->image, x, y, 0xFFFF00);
}

void render(t_fractal *fractol) 
{
    int x = 0;
    int y;
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
    mlx_put_image_to_window(fractol->mlx, fractol->window, fractol->image.img, 0, 0);
}