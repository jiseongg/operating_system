/* Prototype
 *
 * #include <sys/types.h>
 * #include <sys/wait.h>
 * pid_t wait(int *status);
 *
 * 1. error
 * ECHILD: the calling process does not have any children.
 * EINTR: a signal was received while waiting, and the call returned early.
 *
 * 2. status
 * contains additional information about the child.
 * defined in "sys/wait.h"
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int status;
	pid_t pid;
	if(!fork())
	{
		/* child will be immediately exited */
		return 1;
		
		/* SIGABORT signal */
//		abort();
	}

	pid = wait(&status);
	if(pid == -1)
	{
		perror("wait");
	}

	printf("pid = %d\n", pid);

	if(WIFEXITED(status))
	{
		printf("Normal termination with exit status = %d\n",
				WEXITSTATUS(status));
	}

	if(WIFSIGNALED(status))
	{
		printf("Killed by signal = %d%s\n",
				WTERMSIG(status), WCOREDUMP(status) ? " (dumped core)" : "");
	}

	if(WIFSTOPPED(status))
	{
		printf("Stopped by signal=%d\n",
				WSTOPSIG(status));
	}

	if(WIFCONTINUED(status))
	{
		printf("Continued\n");
	}

	return 0;
}
