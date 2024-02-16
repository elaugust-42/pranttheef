#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *ptr;

    ft_printf("pointer myptf: %p\n", &ptr);
    printf("pointer real printf: %p\n", &ptr);
    return (0);
}