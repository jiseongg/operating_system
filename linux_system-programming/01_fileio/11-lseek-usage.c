#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int fd;
	char *buf1 = "I love linux.";
	char *buf2 = "hate";
	ssize_t nr;
	off_t ret;
	size_t len;
	char *buf3;

	fd = open("./files/11-file", O_RDWR | O_CREAT, 0644);
	if(fd == -1)
	{
		perror("open");
		return 0;
	}

	nr = write(fd, buf1, strlen(buf1));
	if(nr == -1)
	{
		perror("write");
		return 0;
	}

	/* 2 ways to replace love to hate */
	ret = lseek(fd, (off_t) 2, SEEK_SET);
//	ret = lseek(fd, (off_t) -11, SEEK_END);
	if(ret == (off_t) -1)
	{
		perror("lseek");
		return 0;
	}

	nr = write(fd, buf2, strlen(buf2));
	if(nr == -1)
	{
		perror("write");
		return 0;
	}


	/* make holes with SEEK_END and positive pos */
	ret = lseek(fd, (off_t) 10, SEEK_END);
	if(ret == (off_t) -1)
	{
		perror("lseek");
		return 0;
	}

	nr = write(fd, buf1, strlen(buf1));
	if(nr == -1)
	{
		perror("write");
		return 0;
	}


	/* print holes */
	ret = lseek(fd, (off_t) 0, SEEK_SET);
	if(ret == (off_t) -1)
	{
		perror("lseek");
		return 0;
	}
	
	len = strlen(buf1)*2 + 10;
	buf3 = (char*)malloc(sizeof(char) * len);
	while(len != 0 && (ret = read(fd, buf3, len)) != 0)
	{
		if(ret == -1)
		{
			if(errno == EINTR)
				continue;
			perror("read");
			break;
		}

		len -= ret;
		buf3 += ret;
	}

	/* holes will not be printed */
	buf3 -= 36;
	for(int i = 0; i < 36; i++)
	{
		printf("%c", buf3[i]);
	}
	printf("\n");
	return 0;
}
