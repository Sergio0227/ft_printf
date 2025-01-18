#include "../includes/ft_printf.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	void *x;

	printf("%p\n", x);
	ft_printf("%p", x);
	return 0;
}
