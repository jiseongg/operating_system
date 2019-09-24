/* Prototype
 *
 * #include <sys/uio.h>
 *
 * ssize_t writev(int fd, const struct iovec *iov, int count);
 * 
 * return: # of bytes (count * iov_len)
 *
 * struct iovec
 * {
 *     void *iov_base;		// pointer to start of buffer
 *     size_t iov_len;		// size of buffer in bytes
 * }
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>

int main()
{
	struct iovec iov[3];
	ssize_t nr;
	int fd, i;

	char *buf[] = {
			"The term buccaneer comes from the word boucan.\n",
			"A boucan is a wooden frame used for cooking meat.\n",
			"Buccaneer is the West Indies name for a pirate.\n"
	};

	fd = open("./files/01-file", O_WRONLY | O_CREAT | O_TRUNC);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}

	/* fill out three iovec structures. */
	for(i = 0; i < 3; i++)
	{
		iov[i].iov_base = buf[i];
		iov[i].iov_len = strlen(buf[i]) + 1;
	}

	/* with a single call, write them all out */
	nr = writev(fd, iov, 3);
	if(nr == -1)
	{
		perror("writev");
		return 1;
	}

	printf("wrote %ld bytes\n", nr);

	if(close(fd))
	{
		perror("close");
		return 1;
	}
	
	return 0;
}
