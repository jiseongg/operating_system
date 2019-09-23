#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
int main()
{
	int fd;
	/* int open(const char *name, int flags);
	 * int open(const char *name, int flags, mode_t mode);
	 *
	 * flags parameter of open()
	 * O_WRONLY: write only
	 * O_RDONLY: read only
	 * O_CREAT: If file doesn't exist, the kernel will create it.
	 * O_TRUNC: with writing, file will be truncated to zero length
	 *
	 * mode parameter: permissions fo the newly created file
	 * S_IWUSR: Owner has write permission.
	 * S_IWGRP: Group has write permission.
	 * S_IROTH: Everyone else has read permission.
	 * S_IRWXO: Everyone else has read, write, execute permission.
	 */


//	fd = open("./files/01-file", O_WRONLY | O_CREAT | O_TRUNC,
//			S_IWUSR | S_IWGRP);
	
	fd = open("./file/01-file", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	
	if(fd == -1)
	{
		printf("error\n");
		printf("%d\n", errno);
		perror("open");
	}
	return 0;
}
