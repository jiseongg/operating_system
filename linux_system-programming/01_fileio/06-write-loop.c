#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fd;
	char *buf = "I love Linux.";
	ssize_t nr;
	size_t len = strlen(buf);

	fd = open("./files/06-file", O_RDWR | O_CREAT, 0644);
	if(fd == -1)
	{
		perror("open");
		return 0;
	}

	/* loop for partial write */
	while(len != 0 && (nr = write(fd, buf, len)) != 0)
	{
		if(nr == -1)
		{
			if(errno == EINTR)
				continue;
			perror("write");
			break;
		}

		len -= nr;
		buf += nr;
	}

	return 0;
}
