
#include "ft_printf.h"
#include <stdio.h>

int main (void)
{
    int result;

    result = ft_printf("what is this %s %s | %d | %d | %% \n", "shit", "here", 1, 2);
    printf(">> %d\n", result);
    result = printf("what is this %s %s | %d | %d | %%\n", "shit", "here", 1, 2);
    printf(">> %d\n", result);
}