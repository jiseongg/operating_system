#include <sys/select.h>
#include <sys/time.h>
#include <stdio.h>

int main(void)
{
	struct timeval tv;

	tv.tv_sec = 3;
	tv.tv_usec = 500;

	/* sleep for 3.5 seconds */
	select(0, NULL, NULL, NULL, &tv);
}

