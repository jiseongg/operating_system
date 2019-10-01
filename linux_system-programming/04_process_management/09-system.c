/* Prototype
 *
 * #include <stdlib.h>
 *
 * int system (const char *command);
 *
 *
 * when?
 * a process is spawning a child only to immediately wait for
 * its termination. e.g. a simple utility or shell script.
 *
 * return: status of the command as provided by wait()
 *
 * "/bin/sh -c command" is executed
 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
	int ret;
	printf("parent process pid = %d\n\n", getpid());
	ret = system("ls -al");

	if(WIFEXITED(ret))
	{
		printf("Normal termination with exit status = %d\n",
				WEXITSTATUS(ret));
	}

	if(WIFSIGNALED(ret))
	{
		printf("Killed by signal = %d%s\n",
				WTERMSIG(ret),
				WCOREDUMP(ret) ? " (dumped core)" : "");
	}

	if(WIFSTOPPED(ret))
	{
		printf("Stopped by signal = %d\n",
				WSTOPSIG(ret));
	}

	if(WIFCONTINUED(ret))
	{
		printf("Continued\n");
	}

	return 0;
}
