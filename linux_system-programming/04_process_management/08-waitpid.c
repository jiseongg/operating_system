/* Prototype
 *
 * #include <sys/types.h>
 * #include <sys/wait.h>
 *
 * pid_t waitpid(pid_t pid, int *status, int options);
 *
 * 1. pid
 *  <-1: child process whose process group ID is -pid
 *   -1: wait for any child process
 *    0: child process in the same process group as the caller
 *  > 0: wait for child process with corresponding pid
 *
 *  2. status
 *  defined in "sys/wait.h" (same with wait(&status))
 *
 *  3. options
 *  WNOHANG: don't block and return for terminated child
 *  WUNTRACED: let WIFSTOPPED be set
 *  WCONTINUED: let WIFCONTINUED be set
 *
 *  4. return
 *  pid: if child is changed
 *  0: not yet been changed with WNOHANG specified
 *  -1: error
 *  waitpid(-1, &status, 0) = wait(&status);
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status;
	int pid;	

	/* fork child process */
	pid = fork();

	if(pid < 0)
	{
		perror("fork");
		return 1;
	}
	else if(!pid)
	{
		printf("child process: %d\n\n", getpid());
//		sleep(10);
		return 2;
	}
	else
	{
		printf("Parent(%d) is waiting child(%d)\n", getpid(), pid);
		sleep(2);
		int ret = waitpid(pid, &status, 0);
//		int ret = waitpid(pid, &status, WNOHANG);
		printf("ret = %d\n", ret);
		if(WIFEXITED(status))
		{
			printf("Normal termination with exit status = %d\n",
					WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status))
		{
			printf("Killed by signal = %d%s\n\n",
					WTERMSIG(status),
					WCOREDUMP(status) ? " (dumped core)" : "");
		}
	}
	return 0;
}
