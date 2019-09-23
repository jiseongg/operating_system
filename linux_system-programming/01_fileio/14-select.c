/* Prototype
 *
 * #include <sys/select.h>
 * int select(int n,
 *			  fd_set *readfds,
 *			  fd_set *writefds,
 *			  fd_set *exceptfds,
 *			  struct timeval *timeout);
 *
 * FD_CLR(int fd, fd_set *set);
 * FD_ISSET(int fd, fd_set, *set);
 * FD_SET(int fd, fd_set *set);
 * FD_ZERO(fd_set *set);
 */

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>

#define TIMEOUT 5
#define BUF_LEN 1024

int main(void)
{
	struct timeval tv;
	fd_set readfds;
	int ret;

	/* Wait on stdin for input. */
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	/* Wait up to five seconds */
	tv.tv_sec = TIMEOUT;
	tv.tv_usec = 0;

	/* All right, now block! */
	ret = select(STDIN_FILENO + 1,
				 &readfds,
				 NULL,
				 NULL,
				 &tv);

	if(ret == -1)
	{
		perror("select");
		return 1;
	}
	else if(!ret)
	{
		printf("%d seconds elapsed.\n", TIMEOUT);
		return 0;
	}

	/*
	 * Is our file descriptor ready to read?
	 * (It must be, as it was the only fd that
	 * we provided and the call returned nonezero.)
	 */
	if(FD_ISSET(STDIN_FILENO, &readfds))
	{
		char buf[BUF_LEN + 1];
		int len;

		/* guaranteed to not block */
		len = read(STDIN_FILENO, buf, BUF_LEN);
		if(len == -1)
		{
			perror("read");
			return 1;
		}
		if(len)
		{
			buf[len] = '\0';
			printf("read: %s\n", buf);
		}

		return 0;
	}

	fprintf(stderr, "This should not happen!\n");
	return 1;
}

