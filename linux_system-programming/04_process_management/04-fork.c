/* Prototype
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t fork (void);
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <inttypes.h>

int main()
{
	pid_t pid;

	printf("pid of parent process: %jd\n", (intmax_t)getpid()); 

	pid = fork();
	if(pid > 0)
	{
		/* parent will execute this */
		printf("forked process: %d.\n", pid);
	}
	else if(pid == 0)
	{
		/* child will execute this */
		printf("\npid = %d at child process.\n", pid);
		printf("I am the child. pid is %jd.\n", (intmax_t)getpid());
		printf("Parent process is %jd.\n", (intmax_t)getppid());
	}
	else if(pid == -1)
	{
		perror("fork");
		return 1;
	}

	return 0;
}
