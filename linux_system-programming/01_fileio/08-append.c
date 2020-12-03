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
	const char *buf1 = "I love Linux.\n";
	const char *buf2 = "I love C++.\n";
	size_t len1 = strlen(buf1);
	size_t len2 = strlen(buf2);

	fd = open("./files/08-file", O_RDWR | O_CREAT | O_APPEND, 0644);
	if(fd == -1)
	{
		perror("open");
		return 0;
	}

	if(write(fd, buf1, len1) == -1)
	{
		perror("write");
		return 0;
	}

	if(write(fd, buf2, len2) == -1)
	{
		perror("write");
		return 0;
	}

	if(fsync(fd) == -1)
	{
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
