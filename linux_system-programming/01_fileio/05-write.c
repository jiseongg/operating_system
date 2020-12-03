#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int fd;
	ssize_t nr;
	const char *buf = "I love Linux.";
	size_t len = strlen(buf);

	/* open file */
	fd = open("./files/05-file", O_RDWR, 0644);
//	fd = open("./file/05-file", O_RDWR, 0644); // error
	if(fd == -1)
	{
		perror("open");
	}

	/* write the string in 'buf' to 'fd */
	nr = write(fd, buf, len);
//	nr = write(fd+3, buf, len);
	/* error detecting with respect to write() */
	if(nr == -1)
	{
		perror("write");
		return 0;
	}
	else if(nr != len)
	{
		printf("incomplete write");
	}

	char *word = (char*)malloc(sizeof(char) * len);

	fd = open("./files/05-file", O_RDONLY, 0644);
	while(len != 0 && (nr = read(fd, word, len)) != 0)
	{
		if(nr == -1)
		{
			if(errno == EINTR)
				continue;
			perror("read");
			break;
		}

		printf("%s\n", word);
		len -= nr;
		buf += nr;
	}

	return 0;
}
