/* #include <unistd.h>
 * int nice(int inc);	// get nice value (-20 to 19)
 *
 * decreasing: only possible for a process with the CAP_SYS_NICE capability
 *
 *
 *
 * #include <sys/time.h>
 * #include <sys/resource.h>
 * int getpriority(int which, int who);				// returns the highest priority
 * int setpriority(int which, int who, int prio);	// set the priority of all
 *
 * which: PRIO_PROCESS, PRIO_PGRP, PRIO_USER
 * who: process ID, process group ID, user ID
 *
 * who = 0: operates on the current process, process group user
 */

#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main()
{
	int ret, val;

	/* get current nice value */
	val = nice(0);
	printf("current nice value is %d\n", val);

	val = 10 - val;
	errno = 0;

	/* set the nice value to 10 */
	ret = nice(val);
	if(ret == -1 && errno != 0)
		perror("nice");
	else
		printf("nice value is now %d\n", ret);

	
	/* get current priority of the process */
	ret = getpriority(PRIO_PROCESS, 0);
	if(ret == -1 && errno != 0)
		perror("getpriority");
	else
		printf("\nnice value is now %d\n", ret);

	/* set priority of the process */
	ret = setpriority(PRIO_PROCESS, 0, 11);		// decreasing: permission is needed
	if(ret == -1)
		perror("setpriority");

	ret = getpriority(PRIO_PROCESS, 0);
	if(ret == -1 && errno != 0)
		perror("getpriority");
	else
		printf("nice value is now %d\n", ret);

	return 0;
}
