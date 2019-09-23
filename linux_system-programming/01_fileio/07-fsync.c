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

	fd = open("./files/07-file", O_RDWR | O_CREAT, 0644);
	if(fd == -1)
	{
		perror("open");
		return 0;
	}

	nr = write(fd, buf, len);
	if(nr == -1)
	{
		perror("write");
		return 0;
	}

	if(fsync(fd) == -1)
	{
		/* if fsync() failes, try fdatasync() */
		if(errno == EINVAL)
		{
			if(fdatasync(fd) == -1)
			{
				perror("fdatasync");
			}
		}
		else
			perror("fsync");
	}

	return 0;
}
