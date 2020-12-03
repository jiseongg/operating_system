#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
// for read() funtion
#include <unistd.h>

int main()
{
	/* ssize_t read(int fd, void *buf, size_t len);
	 */
	int fd;
	char word;
	ssize_t nr;

	/* no directory named file.
	 * errno = 9: bad file descripter
	 */
//	fd = open("./file/03-file", O_RDONLY | O_CREAT | O_TRUNC, 0644);

	fd = open("./files/03-file", O_RDONLY | O_CREAT | O_TRUNC, 0644);

	nr = read(fd, &word, sizeof(char));
	if(nr == -1)
	{
		printf("error!\n");
		printf("%d\n", errno);
		printf("%s\n", strerror(errno));
		return 0;
	}

	printf("%ld\n", nr);
	printf("%c\n", word);
	return 0;
}
