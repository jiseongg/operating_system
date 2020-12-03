/* Daemonize procedure (make it runs in the background)
 * 1. call fork()
 * 2. parent calls exit()
 * 3. child calls setsid(),
 *	  becomes without associated controlling terminal
 * 4. change the working directory (because the inherited might be random)
 * 5. close all file descriptors
 * 6. open file descripters 0, 1, 2 (stdin, stdout, stderr)
 *	  and redirect them to /dev/null
 *
 *
 * function provided by C library
 * 
 * #include <unistd.h>
 * int daemon(int nochdir, int noclose)
 *
 * nochdir != 0: will not change working directory to the root
 * noclose != 0: will not close all open file descriptors.
 */

/* Implementation of daemonizing function */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/limits.h>

int main(void)
{
	pid_t pid;
	int i;

	/* create new process */
	pid = fork();
	if(pid == -1)
	{
		perror("fork");
		return -1;
	}
	else if(pid != 0)
	{
		/* terminate the parent */
		exit(EXIT_SUCCESS);
	}

	/* create new session and process group */
	if(setsid() == -1)
	{
		perror("setsid");
		return -1;
	}

	/* set the working directory to the root directory */
	if(chdir("/") == -1)
	{
		perror("chdir");
		return -1;
	}

	printf("NR_OPEN: %d\n", NR_OPEN);
	printf("pid: %d\n", getpid());
	/* close all open file--NR_OPEN is overkill, but works */
	for(i = 0; i < NR_OPEN; i++)
	{
		close(i);
	}

	/* redirect fd's 0, 1, 2 to /dev/null */
	open("/dev/null", O_RDWR);	// stdin
	dup(0);						// stdout
	dup(0);						// stderr

	/* do its daemon things... */

	return 0;
}

