#include "raycast3d.h"

void	print_and_exit(char *message, int fd, int exit_code)
{
	if (exit_code == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", fd);
		ft_putstr_fd(message, fd);
	}
	else
		ft_putstr_fd(message, fd);
	ft_putstr_fd("\n", fd);
	exit(exit_code);
}
