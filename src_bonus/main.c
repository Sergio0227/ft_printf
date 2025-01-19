#include "../includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	x;
	int	d;
	int	i;

	printf("%d", printf("%-2ca", 0));
	printf("\n");
	printf("%d", ft_printf("%-2ca", 0));

	// ft_printf(" %-s ", "-");
	return (0);
}
