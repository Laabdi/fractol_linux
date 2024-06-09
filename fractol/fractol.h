#ifndef FRACTOL_H
# define FRACTOL_H

#include "./minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <X11/Xlib.h>

#define WIDTH 800
#define HEIGHT 800
#define DESTROY_NOTIFY 29
#define XK_BackSpace                     0xff08  /* Back space, back char */
#define XK_Tab                           0xff09
#define XK_Linefeed                      0xff0a  /* Linefeed, LF */
#define XK_Clear                         0xff0b
#define XK_Return                        0xff0d  /* Return, enter */
#define XK_Pause                         0xff13  /* Pause, hold */
#define XK_Scroll_Lock                   0xff14
#define XK_Sys_Req                       0xff15
#define XK_Escape                        0xff1b
#define XK_Delete                        0xffff  /* Delete, rubout */
typedef struct s_complex 
{
    double real;
    double imag;
} t_complex;

typedef struct s_img 
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;

typedef struct s_fractal 
{
    void *mlx;
    void *window;
    t_img image;
    double shift_x;
    double shift_y;
    double zoom;
    int iterations_defintion;
} t_fractal;

t_complex   sum_comp(t_complex z, t_complex c);
t_complex   square_comp(t_complex z) ;
double      getScaledValue(double value, double sourceRangeMin, double sourceRangeMax, double targetRangeMin, double targetRangeMax);
int	        close_window(t_fractal *fractol);
int         ft_strncmp(char *s1,char *s2, int n);
void        ft_putstr(char *s);
void        render(t_fractal *fractol) ;
int         events_handler(int keysym,t_fractal *fractol);
void        mlx_key_gere(t_fractal *fractol);
void cleanup_and_exit(t_fractal *fractol);

# endif