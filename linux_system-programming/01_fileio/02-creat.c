#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	/* int creat(const char *name, mode_t mode);
	 *
	 * same with open function with O_CREAT flags
	 */
	int fd;
	fd = creat("./files/02-file", 0644);
	if(fd == -1)
		printf("error!\n");
	printf("%d\n", fd);
	return 0;
}
