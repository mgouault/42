#include "../mgouault/get_next_line.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	char	*line;
	int		ret;
	int		fd;

	line = NULL;
	if (ac != 2)
		exit(EXIT_FAILURE);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	while ((ret = get_next_line(fd, &line)) > -1)
	{
		ft_putendl(line);
		if (line != NULL)
			free(line);
		if (ret == 0)
			break ;
	}
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	return (0);
}
