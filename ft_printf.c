#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

static void ft_specifier(char s, va_list *args, int *len, int *i)
{
	if(s == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if(s == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if(s == 'p')
		ft_putptr(va_arg(*args, size_t), len);
	else if (s == 'd'|| s == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if(s == 'u')
		ft_putunsigned(va_arg(*args, unsigned int), len);
	else if(s == 'x')
		ft_puthex(va_arg(*args, unsigned int), len, 'x');
	else if(s == 'X')
		ft_puthex(va_arg(*args, unsigned int), len, 'X');
	else if(s == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int     i;
	int     len;
	
	i = 0;
	len = 0;
	va_start(args, format);
	while(format[i])
	{
		if(format[i] == '%')
		{
			i++;
			ft_specifier(format[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar((char)format[i], &len);
			i++;
		}
	}
	
	va_end(args);
	return(len);
	
}
// #include "ft_functions.c"

// int	main(void)
// {
// 	int x = 5678;
// 	ft_printf("moloko %s is good, %d points\n", "milk", 100);
// 	printf("original moloko %s is good, %d points\n", "milk", 100);
	
// 	ft_printf("number %d in hex is %x \n", 7896, 7896);
// 	ft_printf("number %d in hex is %X \n", 7896, 7896);
// 	printf("original number %d in hex is %x\n", 7896, 7896);
// 	printf("original number %d in hex is %X\n", 7896, 7896);
	
	
// 	ft_printf("number %d in base 16 format is %p\n", 5678, &x);
// 	printf("original number %d in base 16 format is %p\n", 5678, &x);
	
// 	ft_printf("%%\n");
// 	printf("original %%");
// }