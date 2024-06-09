#include "raycast3d.h"

int	get_data_from_file(char *filename, t_data *data)
{
	int		n_elements;
	int		fd;

	n_elements = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_and_exit("Failed to open file", 2, EXIT_FAILURE);
	load_elements(&n_elements, data, fd);
	if (n_elements != 6)
		return (FAILURE);
	if (load_map(data, fd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
