#include "../get_next_line/get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	char *line;

	for(int i = 1; i < argc; i++)
	{
		int fd = open(argv[i], O_RDONLY);
		printf("READING FILE %s\n", argv[i]);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("%s", line);
			free(line);
		}
		close(fd);
		printf("End OF File\n");
	}
	return 0;
}
