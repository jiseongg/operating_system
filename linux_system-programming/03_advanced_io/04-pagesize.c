/* Prototype
 *
 * #include <unistd.h>
 * long sysconf(int name);		// standard POSIX method
 * int getpagesize(void);
 * 
 * #include <sys/user.h>
 * #define PAGE_SIZE
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/user.h>

int main()
{
	long page_size_1 = sysconf(_SC_PAGE_SIZE);
	int page_size_2 = getpagesize();
	int page_size_3 = PAGE_SIZE;

	printf("page size is...\n");
	printf("%ld, %d, %d\n", page_size_1, page_size_2, page_size_3);

	return 0;
}
