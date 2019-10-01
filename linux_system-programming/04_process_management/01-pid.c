/* Prototype
 *
 * #include <sys/types.h>
 * #include <unistd.h>
 *
 * pid_t getpid(void);
 * pid_t getppid(void);
 */

#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdio.h>

int main()
{
	printf("My pid=%jd\n", (intmax_t) getpid());
	printf("Parent's pid=%jd\n", (intmax_t) getppid());

	return 0;
}

