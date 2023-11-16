#include "./includes/push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int fd = open("output.txt", O_RDONLY);
	char *out = get_next_line(fd);
	int count = 0;
	while (out)
	{
		count++;
		if (ft_strncmp("Is sorted!\n", out, ft_strlen(out)) == 0)
			ft_printf("Is sorted!\n");
		free(out);
		out = get_next_line(fd);
	}
	if (out)
		free(out);
	// ft_printf("Total actions: %i\n", count);
	return (0);
}
