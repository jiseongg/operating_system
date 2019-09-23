/* prototype
 *
 * #include <stdio.h>
 *
 * size_t fread(void *buf, size_t size, size_t nr, FILE *stream);
 * read up to nr elements of data, each of size bytes
 * return: the number of elements read (EOF or less than nr: error)
 */

#include <stdio.h>

int main()
{
	FILE *stream;
	char buf[64];
	size_t nr;

	stream = fopen("./files/04-file", "r");
	if(stream == NULL)
	{
		perror("fopen");
	}

	nr = fread(buf, sizeof(char), 14, stream);
	if(nr == 0)
	{
		perror("fread");
	}

	printf("%s\n", buf);

	return 0;
}
