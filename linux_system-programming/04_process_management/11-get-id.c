/* Prototype
 *
 * #include <unistd.h>
 * #include <sys/types.h>
 *
 *
 * uid_t getuid(void);	// get real user ID
 * gid_t getgid(void);	// get real group ID
 * uid_t geteuid(void); // get effective user ID
 * gid_t getegid(void); // ger effective group ID
 *
 */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	uid_t uid, euid;
	gid_t gid, egid;

	/* get real and effective user IDs */
	uid = getuid();
	euid = geteuid();

	/* get real and effective group IDs */
	gid = getgid();
	egid = getegid();

	/* root user may print 0 */
	printf("uid: %d, euid: %d\n", uid, euid);
	printf("gid: %d, egid: %d\n", gid, egid);

	return 0;
}
