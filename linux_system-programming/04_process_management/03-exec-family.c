/* Prototype
 *
 * #include <unistd.h>
 *
 * int execlp (const char *file, const char *arg, ...);
 *
 * int execle (const chat *path, const char *arg, ..., char *const envp[]);
 *
 * int execv (const char *path, char *const argv[]);
 *
 * int execvp (const char *file, char *const argv[]);
 *
 * int execve (const char *filename, char *const argv[], char *const envp[]);
 *
 * meanings of l, v, p
 * l : arguments are provided via a list
 * v : arguments are provided via an array (vector)
 * p : denotes that the user's full path is searched for the given file.
 * e : a new environment is also supplied for the new process.
 */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

/* default environment variables */
extern char **environ;

int main()
{
	int ret;
	
//	ret = execl("/bin/ls", "ls", "-al", NULL);
//	if(ret == -1)
//	{
//		perror("execle");
//		return 1;
//	}

//	ret = execlp("ls", "ls", "-al", NULL);
//	if(ret == -1)
//	{
//		perror("execlp");
//		return 1;
//	}

//	ret = execle("/bin/ls", "ls", "-al", NULL, environ);
//	if(ret == -1)
//	{
//		perror("execle");
//		return 1;
//	}

	char *arg[] = {"ls", "-al", NULL};

//	ret = execv("/bin/ls", arg);
//	if(ret == -1)
//	{
//		perror("execv");
//		return 1;
//	}

//	ret = execvp("ls", arg);
//	if(ret == -1)
//	{
//		perror("execvp");
//		return 1;
//	}

	/* the lone system call */
	ret = execve("/bin/ls", arg, environ);
	if(ret == -1)
	{
		perror("execve");
		return 1;
	}

	return 0;
}
