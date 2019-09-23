/* Prototype
 *
 * #include <stdio.h>
 * FILE* fdopen(int fd, const char *mode);
 * int fclose(FILE *stream);
 * int fcloseall(void);
 *
 * fdopen: converts an already open file descriptor to a stream
 * 
 * fclose: closes a given stream. (it also closes fd.)
 *		   success: return 0.
 *		   failure: return EOF and sets errno appropriately.
 * fcloseall: closes all streams. always return 0.
 *
 * before closing: streams are flushed
 */

#define _GNU_SOURCE		//to use fcloseall
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	FILE *stream;
	int fd, ret;

//	fd = open("./files/nonexistent", O_RDWR);
	fd = open("./files/02-file", O_RDWR | O_CREAT, 0644);
	if(fd == -1)
	{
		perror("open");
	}

	/* closing stream will close the fd as well. */
	stream = fdopen(fd, "r");
	if(!stream)
	{
		perror("fdopen");
	}

	ret = fclose(stream);
	if(ret == -1)
	{
		perror("fclose");
	}

	fcloseall();
	
	return 0;
}

