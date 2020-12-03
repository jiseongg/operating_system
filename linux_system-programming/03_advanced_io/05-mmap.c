/* Prototype
 *
 * #include <sys/mman.h>
 * void * mmap (void *addr,
 *              size_t len,
 *              int prot,
 *              int flags,
 *              int fd,
 *              off_t offset);
 *
 * prot: PROT_READ, PROT_WRITE, PROT_EXEC
 * must not conflict with the open mode of the file.
 *
 * flags: MAP_FIXED, MAP_PRIVATE, MAP_SHARED
 * describes the type of mapping. (shared or not by processes)
 *
 *
 * removing a mapping:
 *
 * #include <sys/mman.h>
 * int munmap(void *addr, size_t len);
 */

#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	off_t len;
	char *p;
	int fd;

	/* if file is not passed */
	if(argc < 2)
	{
		fprintf(stderr, "usage: %s <file>\n", argv[0]);
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		perror("open");
		return 1;
	}

	/* returns information about a given file */
	if(fstat(fd, &sb) == -1)
	{
		perror("fstat");
		return 1;
	}

	/* whether the file is regular file */
	if(!S_ISREG(sb.st_mode))
	{
		fprintf(stderr, "%s is not a file\n", argv[1]);
		return 1;
	}

	/* mapping */
	p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		perror("mmap");
		return 1;
	}

	/* close the file */
	if(close(fd) == -1)
	{
		perror("close");
		return 1;
	}

	/* prints the file byte-by-byte */
	for(len = 0; len < sb.st_size; len++)
		putchar(p[len]);

	if(munmap(p, sb.st_size) == -1)
	{
		perror("munmap");
		return 1;
	}

	return 0;
}
