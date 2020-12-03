/* Prototype
 *
 * #include <poll.h>
 * 
 * int poll(struct poofd *fds, nfds_t nfds, int timeout);
 *
 * struct pollfd
 * {
 *			int fd;			// file descriptor
 *			short events;	// requested events to watch
 *			short revent;	// returned events witnessed
 * }
 *
 *
 * valid events
 * POLLIN: There is data to read
 * POLLRDNORM: There is normal data to read.
 * POLLRDBAND: There is priority data to read.
 * POLLPRI: There is urgent data to read.
 * POLLOUT: Writing will not block
 * POLLWRNORM: Writing normal data will not block.
 * POLLWRBAND: Writing priority data will not block.
 * POLLMSG: A SIGPOLL message is available.
 *
 * POLLIN | POLLPRI: select() read events
 * POLLOUT | POLLWRBAND: select() write events
 * POLLRDNORM | POLLRDBAND = POLLIN
 *
 *
 * valid revents
 * POLLER: Error on the given fd.
 * POLLHUP: Hung up event on the given file descriptor.
 * POLLNVAL: The given file descriptor is invalid.
 *
 * errno
 * EBADF: An invalid fd.
 * EFAULT: The pointer to fds pointed outside of the process's address space.
 * EINTR: A signal occurred before any requested event.
 * EINVAL: The nfds parameter exceeded the RLIMIT_NOFILE value.
 * ENOMEM: Insufficient memory was available to complete the request.
 */
 
#include <stdio.h>
#include <unistd.h>
#include <poll.h>

#define TIMEOUT 5

int main(void)
{
	struct pollfd fds[2];
	int ret;

	/* watch stdin for input */
	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;

	/* watch stdout for ability to write (almost always true) */
	fds[1].fd = STDOUT_FILENO;
	fds[1].events = POLLOUT;

	/* All set, block! */
	ret = poll(fds, 2, TIMEOUT * 1000); //5 seconds
	if(ret == -1)
	{
		perror("poll");
		return 1;
	}

	if(!ret)
	{
		printf("%d seconds elapsed.\n", TIMEOUT);
		return 0;
	}

	if(fds[0].revents & POLLIN)
	{
		printf("stdin is readable\n");
	}
	if(fds[1].revents & POLLOUT)
	{
		printf("stdout is writable\n");
	}

	return 0;
}


