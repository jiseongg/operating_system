#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

extern char **environ;

int main()
{
	pid_t pid;
	char *args[] = {"ls", "-al", NULL};

	printf("pid of parent process: %jd\n\n", (intmax_t)getpid());
	pid = fork();

	/* fork error */
	if(pid == -1)
	{
		perror("fork");
		return 1;
	}

	/* child execute this */
	if(pid > 0)
	{
		printf("parent process: %jd\n", (intmax_t)getpid());
		int ret;
		ret = execve("/bin/ls", args, environ);
		if(ret == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("child process: %jd\n", (intmax_t)getpid());
		int ret;

		ret = execve("/bin/ls", args, environ);
		if(ret == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}

