#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx,fractal->image.img);
	mlx_destroy_window(fractal->mlx,fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int events_handler(int keysym, t_fractal *fractol)
{
    if (keysym == XK_Escape) 
    close_handler(fractol);
    else if (keysym == 65363)
    fractol->shift_x+= (0.5 * fractol->zoom);
    else if (keysym == 65361)  
     fractol->shift_x-= (0.5 * fractol->zoom);
    else if (keysym == 65364)
     fractol->shift_y+= (0.5 * fractol->zoom);
    else if (keysym == 65362)
    fractol->shift_y-= (0.5 * fractol->zoom);
    else if (keysym == 65451) //plus
    fractol->iterations_defintion += 10;
    else if (keysym == 65453) //minus
    fractol->iterations_defintion -= 10;
    render(fractol); 
    return 0;
}
int	mouse_handler(int button, int x, int y, t_fractal *fractol)
{
    (void)x;
    (void)y;
    if(button == Button4)
    {
        fractol->zoom *= 1.05;
    }
    else if(button == Button5)
    {
        fractol->zoom *= 0.95;
    }
    render(fractol);
    return 0;
}

void mlx_key_gere(t_fractal *fractol)
{
    mlx_hook(fractol->window, KeyPress, KeyPressMask, events_handler, fractol);
    mlx_hook(fractol->window, DestroyNotify, StructureNotifyMask, close_handler, fractol);
    mlx_hook(fractol->window,ButtonPress,ButtonPressMask,mouse_handler,fractol);
}
