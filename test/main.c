#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int	main(void)
{
	int		fd;
	char	*line;
	int		line_num = 1;

	fd = open("test_file", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line %d: %s", line_num++, line);
		fflush(stdout);
		free(line);
	}

	// line = get_next_line(fd);
	// printf("line %d: %s", line_num++, line);
	// fflush(stdout);
	// free(line);

	// line = get_next_line(fd);
	// printf("line %d: %s", line_num++, line);
	// fflush(stdout);
	// free(line);

	// line = get_next_line(fd);
	// printf("line %d: %s", line_num++, line);
	// fflush(stdout);
	// free(line);

	close(fd);
	return (0);
}
