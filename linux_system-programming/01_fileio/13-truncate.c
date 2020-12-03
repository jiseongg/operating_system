#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int fd, ret;
	const char *sentence = "Edward Teach was a notorious English pirate.\n\
							He was nicknamed Blackbeard.";
	ssize_t nr;

	fd = open("./files/13-file", O_CREAT | O_RDWR, 0644);
	nr = write(fd, sentence, strlen(sentence));
	if(nr == -1)
	{
		perror("write");
	}

	/* int ftruncate(int fd, off_t len);
	 * int truncate(const char *path, off_t len);
	 * if len > total bytes in file, holes are made
	 */
	ret = ftruncate(fd, 45);
	if(ret == -1)
	{
		perror("truncate");
		return -1;
	}

	return 0;

}
