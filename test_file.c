#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int fd = open("random_sentences.txt", O_RDONLY);
	char *line;

	if (fd == -1)
	{
		printf("Error opening file");
		return (0);
	}
	while ((line = get_next_line(fd)) != NULL) 
	{
		printf("Line: %s", line);
		free(line);
	}
	close(fd);
}