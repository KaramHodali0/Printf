#include "ft_printf.h"

int main ()
{
    ft_printf("hello %s\n", "Karam");
    ft_printf("number = %d\n", 42);
    ft_printf("char = %c\n", 'A');
    ft_printf("unsigned = %u\n", 42u);
    ft_printf("hex = %x\n", 255);
    ft_printf("HEX = %X\n", 255); 
    ft_printf("percent = %%\n");
}