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

double ft_atodbl(char *s)
{
    int i = 0;
    int sign = 1;
    double result = 0.0;
    double decimal_place = 1.0;

    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;

    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }
   
    if (s[i] == '.')
    {
        i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            decimal_place /= 10;
            result += (s[i] - '0') * decimal_place;
            i++;
        }
    }
    return result * sign;
}

