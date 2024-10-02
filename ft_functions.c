#include "ft_printf.h"

void    ft_putstr(char *str, int *len)
{
    if(str == NULL)
        str = "(null)";
    while(*str)
        ft_putchar(*str++, len);
}
void    ft_putptr(size_t ptr, int *len)
{
    char    str[17];
    int     i;
    char    *base;
    
    base = "0123456789abcdef";
    i = 0;
    if(ptr == 0)
    {
        ft_putstr("nil", len);
        return;
    }
    ft_putstr("0x", len);
    while(ptr)
    {
        str[i] = base[ptr % 16];
        ptr /= 16;
        i++;
    }
    while(i--)
        ft_putchar(str[i], len);
}
void    ft_putnbr(long  n, int *len)
{
    if(n < 0)
    {
        ft_putchar('-', len);
        n *= -1;
        ft_putnbr(n, len);
    }
    if(n > 9)
    {
        ft_putnbr(n / 10, len);
        ft_putnbr(n % 10, len);
    }
    else
        ft_putchar(n + '0', len);
}
void    ft_putunsigned(unsigned int u, int *len)
{
    if(u > 9)
    {
        ft_putunsigned(u / 10, len);
        ft_putunsigned(u % 10, len);
    }
    else 
        ft_putchar(u + '0', len);
}
void    ft_puthex(unsigned int hex, int *len, char xSize)
{
    char    str[17];
    int     i;
    char    *base;
    
    if(xSize == 'x')
        base = "0123456789abcdef";
    else 
        base = "0123456789ABCDEF";
    i = 0;
    if(hex == 0)
    {
        ft_putchar('0', len);
        return;
    }
    while(hex)
    {
        str[i] = base[hex % 16];
        hex /= 16;
        i++;
    }
    while(i--)
        ft_putchar(str[i], len);
}