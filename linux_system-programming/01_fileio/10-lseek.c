#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
	off_t ret;
	int fd = open("./files/10-file", O_RDWR | O_CREAT, 0644);

	/* prototype
	 * off_t lseek(int fd, off_t pos, int origin);
	 */
	printf("error list\n");
	printf("=================================================\n");
	printf("EBADF: %d, EINVAL: %d, EOVERFLOW: %d, ESPIPE: %d\n\n",
			EBADF, EINVAL, EOVERFLOW, ESPIPE);

	printf("origin list\n");
	printf("=================================================\n");
	printf("SEEK_CUR: %d, SEEK_END: %d, SEEK_SET: %d\n\n",
			SEEK_CUR, SEEK_END, SEEK_SET);



	/* fd doesn't refer to open file */
	ret = lseek(100, (off_t) 1825, SEEK_SET);
	if(ret == (off_t) -1)
	{
		printf("errno: %d\n", errno);
		printf("%s\n", strerror(errno));
	}

	/* invalid origin armument */
	ret = lseek(fd, (off_t) 1825, -1);
	if(ret == (off_t) -1)
	{
		printf("errno: %d\n", errno);
		printf("%s\n", strerror(errno));
	}

	return 0;
}

