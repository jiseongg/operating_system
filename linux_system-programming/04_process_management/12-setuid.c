#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	/* compile with root user, execute "chmod 4755 a.out".
	 * run with non-root user results rid=nonzero, eid=0
	 */
	printf("rid: %d, eid: %d\n", getuid(), getuid());
	
	/* set uid to root
	 * without setuid permission of root user, it doesn't work
	 */
	setuid(0);

	printf("rid: %d, eid: %d\n", getuid(), getuid());
	
	return 0;
}
