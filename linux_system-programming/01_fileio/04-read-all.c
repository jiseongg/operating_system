#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd;
	char *buf = (char*)malloc(sizeof(char));
	ssize_t ret;
	size_t len = sizeof(char) * 12;

	fd = open("./files/04-file", O_RDONLY, 0644);

	while(len != 0 && (ret = read(fd, buf, 3)) != 0)
	{
		if(ret == -1)
		{
			if(errno == EINTR)		// signal was received before read
				continue;
			perror("read");
			break;
		}

		printf("%s\n", buf);
		len -= ret;
		buf += ret;
	}
	return 0;
}
