#include "fractol.h"

int	close_window(t_fractal *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->window);
	return 0;
}
int events_handler(int keysym, t_fractal *fractol)
{
    if (keysym == 65307) 
    close_window(fractol);
    else if (keysym == 65363)
    fractol->shift_x+= 0.5;
    else if (keysym == 65361)  
     fractol->shift_x-= 0.5;
    else if (keysym == 65364)
     fractol->shift_y+= 0.5;
    else if (keysym == 65362)
    fractol->shift_y-= 0.5;
    render(fractol); 
    return 0;
}
void mlx_key_gere(t_fractal *fractol) 
{
    mlx_hook(fractol->window, KeyPress, KeyPressMask, events_handler, fractol);
}
