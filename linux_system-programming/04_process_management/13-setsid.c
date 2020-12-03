/* Prototype
 *
 * #include <unistd.h>
 * pid_t setsid(void);
 * pid_t getsid(pid_t);
 *
 * 1. setsid:
 * creats a new process group inside of a new session
 * and makes the invoking process the leader of both.
 * 
 * return the session ID of the newly created session.
 * return -1 and set errono code be EPERM (current is already leader.)
 * 
 * 2. getsid:
 * returns the session ID of the process identified by pid.
 * argument 0 returns the session ID of the calling process.
 */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	pid_t pid, sid;

	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}
	else if(pid != 0)
	{
		printf("pid %d is terminated\n\n", getpid());
		/* make the parent terminate,
		 * make the child so-called daemon
		 */
		exit(EXIT_SUCCESS);
	}
	else
	{
		/* make the child perform the setsid() */
		pid = setsid();
		if(pid == -1)
		{
			perror("setsid");
			return -1;
		}
		sid = getsid(0);
		printf("new session id(by setsid): %d\n", pid);
		printf("new session id(by getsid): %d\n", sid);
		printf("pid %d executed setsid\n", getpid());
		/* the original parent's pid may not be printed
		 * since it was terminated
		 */
		printf("parent was %d\n", getppid());
	}

	return 0;
}

