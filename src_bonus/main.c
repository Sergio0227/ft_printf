#include "../includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	x;
	int	d;
	int	i;

	printf(" %2p ", -1);
	printf("\n");
	ft_printf(" %2p ", -1);

	// ft_printf(" %-s ", "-");
	return (0);
}
