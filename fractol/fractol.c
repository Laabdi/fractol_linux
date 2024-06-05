#include "fractol.h"


void mlx_connexion(t_fractal *fractol) 
{
    fractol->mlx = mlx_init();
    fractol->window = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "mandelbrot");
    fractol->image.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    fractol->image.addr = mlx_get_data_addr(fractol->image.img, &fractol->image.bits_per_pixel, &fractol->image.line_length, &fractol->image.endian);
}

int main(int ac,char **av) 
{
    t_fractal fractol;
    if((ac == 2 && ft_strncmp(av[1],"mandalbrot",10) != 0) || (ac == 4 && ft_strncmp(av[1],"Julia", 5) != 0))
    {
        mlx_connexion(&fractol);
        render(&fractol);
        mlx_key_gere(&fractol);
        mlx_loop(fractol.mlx);
    }
    else
    {
        ft_putstr("Wrong passed parametre,please enter the correct form");
    }
    return 0;
}

