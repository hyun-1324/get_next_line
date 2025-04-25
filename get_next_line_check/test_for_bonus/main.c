#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;
	char	*line2;
	int		line_num = 1;
	int		line_num2 = 1;

	fd = open("test_file", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}

	fd2 = open("test_file2", O_RDONLY);
	if (fd2 < 0)
	{
		perror("open");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL && (line2 = get_next_line(fd2)) != NULL)
	{
		printf("line %d: %s", line_num++, line);
		free(line);
		printf("line %d: %s", line_num2++, line2);
		free(line2);
	}


	//  if ((line = get_next_line(fd)) != NULL)
	//  {
	// 	printf("line %d: %s", line_num++, line);
	// 	free(line);
	//  }

	// if ((line2 = get_next_line(fd2)) != NULL)
	// {
	// 	printf("line %d: %s", line_num2++, line2);
	// 	free(line2);
	// }

	//  if ((line = get_next_line(fd)) != NULL)
	//  {
	// 	printf("line %d: %s", line_num++, line);
	// 	free(line);
	//  }

	//  	if ((line2 = get_next_line(fd2)) != NULL)
	// {
	// 	printf("line %d: %s", line_num2++, line2);
	// 	free(line2);
	// }


	close(fd);
	close(fd2);
	return (0);
}
