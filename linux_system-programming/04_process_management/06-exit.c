/* Prototype
 *
 * #include <stdlib.h>
 * void exit(int status); // EXIT_SUCCESS or EXIT_FAILURE
 *
 * 1. 
 * call any functions registered with atexit() or on_exit(),
 * in the reverse order of their registeration.
 *
 * 2.
 * flush all open statndard I/O streams.
 *
 * 3.
 * remove any temporary files created with the tmpfile() function.
 *
 *
 * #include <unistd.h>
 * void _exit(int status);	// called to let the kernel handle rest termination
 *
 * 
 *
 * #include <stdlib.h>
 * void atexit(void (*function)(void));
 *
 * registers the given function to run during normal process termination.
 * (if the process is being terminated via a signal, it is not called)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void out_1(void)
{
	printf("atexit() succeeded to call out_1.\n");
}

void out_2(void)
{
	printf("atexit() succeeded to call out_2.\n");
}

int main()
{
	/* two functions are registered and stored in a stack. */
	atexit(out_1);
	atexit(out_2);

	/* return to 0 call exit() */
	return 0;
}


