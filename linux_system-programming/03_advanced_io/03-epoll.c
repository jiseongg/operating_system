/* Prototype
 *
 * #include <sys/epoll.h>
 *
 * int epoll_create1(int flags);	//flags should be EPOLL_CLOEXEC
 *
 * int epoll_ctl(int epfd, int op, int fd, sturct epoll_event *event);
 * struct epoll_event
 * {
 *     uint32_t events;
 *     epoll_data_t data;
 * } __EPOLL_PACKED;
 * typedef union epoll_data
 * {
 *     void *ptr;
 *     int fd;
 *     uint32_t u32;
 *     uint64_t u64;
 * } epoll_data_t;
 *
 * op: EPOLL_CTL_ + ADD, DEL, MOD
 * epoll_event.events: EPOLLERR, EPOLLET, EPOLLHUP, EPOLLIN,
 *                     EPOLLONESHOT, EPOLLOUT, EPOLLPRI
 *
 * int epoll_wait(int epd, struct epoll_event *events, int maxevents, int timeout);
 */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <stdio.h>

int main()
{
	int fd1, fd2, epfd;
	struct epoll_event event;
	int ret, nr_events;

	fd1 = open("./files/03-file_1", O_RDWR | O_CREAT, 0644);
	if(fd1 == -1)
	{
		perror("open");
		return 1;
	}

	fd2 = open("./files/03-file_2", O_RDWR | O_CREAT, 0644);
	if(fd2 == -1)
	{
		perror("open");
		return 1;
	}

	/* create epoll context */
	epfd = epoll_create1(0);
	if(epfd < 0)
	{
		perror("epoll_create1");
		return 1;
	}

	/* add a new watch on the file */
	event.data.fd = fd1;
	event.events = EPOLLIN | EPOLLOUT;
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd1, &event);
	if(ret)
	{
		perror("epoll_ctl");
		return 1;
	}

	event.data.fd = fd2;
	event.events = EPOLLIN | EPOLLOUT;
	ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd2, &event);
	if(ret)
	{
		perror("epoll_ctl");
		return 1;
	}

	/* remove an existing event on the file associated with fd */
	ret = epoll_ctl(epfd, EPOLL_CTL_DEL, fd2, NULL);
	if(ret)
	{
		perror("epoll_ctl");
		return 1;
	}

	/* wait events */
	nr_events = epoll_wait(epfd, &event, 30, 5000);
	if(nr_events < 0)
	{
		perror("epoll_wait");
		return 1;
	}

	return 0;
}

