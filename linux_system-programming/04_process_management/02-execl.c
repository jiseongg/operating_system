/* Prototype
 *
 * #include <unistd.h>
 * int execl(const char *path,
 *			 const char *arg,
 *			 ...);
 */

#include <unistd.h>
#include <sys/types.h>
#include <inttypes.h>
#include <stdio.h>

int main()
{
	printf("Parent pid of old process = %jd\n", (intmax_t) getppid());
	printf("Old process pid = %jd\n", (intmax_t) getpid());
	printf("New process is called...\n\n");

	int ret;
	/* run a new process, compiled from 01-pid.c */
//	ret = execl("./p", "./p", NULL);
	ret = execl("/usr/bin/vim", "vim", "01-pid.c", NULL);
	if(ret == -1)
	{
		perror("execl");
	}

	return 0;
}
