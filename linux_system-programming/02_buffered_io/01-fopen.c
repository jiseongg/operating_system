/* Prototype
 *
 * #include <stdio.h>
 * FILE* fopen(const char *path, const char *mode);
 *
 * mode lists
 * r: reading. stream position is the start of the file.
 * r+: reading and writing. stream position is the start of the file.
 * w: writing. truncated to zero length(existent), or
 *    created and stream position is the start of the file.
 * w+: reading and writing. truncated to zero length(existent), or
 *     created and stream position is the start of the file.
 * a: writing in append mode. stream position is the end of file.
 *    nonexistent, it is created
 * a+: reading and writing in append mode.
 */

#include <stdio.h>

int main()
{
	FILE* fp;
//	fp = fopen("./files/nonexistent", "r");
	fp = fopen("./files/01-file", "w");
	if(fp == NULL)
	{
		perror("fopen");
		return 0;
	}

	return 0;
}
