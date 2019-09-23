#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd = open("./files/09-file", O_RDWR | O_CREAT, S_IWGRP);
	if(fd == -1)
	{
		perror("open");
	}

	/* int close(int fd); */
	if(close(fd) == -1)
	{
		perror("close");
	}

	return 0;
}
