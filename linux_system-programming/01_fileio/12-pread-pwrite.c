#define _XOPEN_SOURCE 500
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd;
	const char *buf1 = "I like Linux more than MacOS and Windows.";
	const char *buf2 = "less";
	ssize_t ret;

	fd = open("./files/12-file", O_RDWR|O_CREAT, 0644);
	if(fd == -1)
	{
		perror("open");
	}

	ret = write(fd, buf1, strlen(buf1));
	if(ret == -1)
	{
		perror("write");
	}

	char *word = (char*)malloc(sizeof(char) * 10);

	/* update current position to 'Windows.' */
	ret = lseek(fd, (off_t) -8, SEEK_END);
	if(ret == (off_t) -1)
	{
		perror("lseek");
	}

	/* ssize_t pread(int fd, void *buf, size_t count, off_t pos);
	 *
	 * read 'like' from file
	 */
	ret = pread(fd, word, 4, (off_t) 2);
	if(ret == -1)
	{
		perror("pread");
	}
	printf("%s\n", word);

	/* ssize_t pwrite(int fd, const void *buf, size_t count, off_t pos);
	 *
	 * write buf2('less') to file
	 */
	ret = pwrite(fd, buf2, strlen(buf2), (off_t) 13);
	if(ret == -1)
	{
		perror("pwrite");
	}

	/* read 'like' from file */
	ret = pread(fd, word, 4, (off_t) 13);
	if(ret == -1)
	{
		perror("pread");
	}
	printf("%s\n", word);

	/* pread, pwrite do not update the file position,
	 * thus read() reads 'Windows.' */
	ret = read(fd, word, 8);
	if(ret == -1)
	{
		perror("read");
	}
	printf("%s\n", word);

	return 0;
}

