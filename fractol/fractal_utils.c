#include "fractol.h"

int ft_strncmp(char *s1,char *s2, int n)
{
    int i = 0;
    while(i < n && s1[i] && s2[i])
    {
        if(s1[i] != s2[i])
        return(s1[i] - s2[i]);
    i++;
    }
    return(s1[i] - s2[i]);
}
void    ft_putstr(char *s)
{
    while(*s)
    {
        write(1, s, 1);
        s++;
    }
}
