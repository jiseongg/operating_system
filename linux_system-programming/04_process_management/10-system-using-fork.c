/*
 * my_system - synchronously spawns and waits for the command.
 * "/bin/sh -c <cmd>".
 *
 * Returns * -1(error), or exit code.
 * Does not block or ignore any signals.
 */

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_system(const char *cmd)
{
	int status;
	pid_t pid;

	pid = fork();
	if(pid == -1)
	{
		return -1;
	}
	else if(pid == 0)
	{
		const char *argv[4];

		argv[0] = "sh";
		argv[1] = "-c";
		argv[2] = cmd;
		argv[3] = NULL;
		execv("/bin/sh", argv);

		exit(-1);
	}

	if(waitpid(pid, &status, 0) == -1)
	{
		return -1;
	}
	else if(WIFEXITED(status))
	{
		return WEXITSTATUS(status);
	}

	return -1;
}

int main()
{
	int ret;
	ret = my_system("ls -al");

	if(WIFEXITED(ret))
	{
		printf("\nNormal termination with exit status = %d\n",
				WEXITSTATUS(ret));
	}

	if(WIFSIGNALED(ret))
	{
		printf("\nKilled by signal = %d%s\n",
				WTERMSIG(ret),
				WCOREDUMP(ret) ? " (dumped core)" : "");
	}

	if(WIFSTOPPED(ret))
	{
		printf("\nStopped by signal = %d\n",
				WSTOPSIG(ret));
	}

	if(WIFCONTINUED(ret))
	{
		printf("\nContinued\n");
	}

	return 0;
}
