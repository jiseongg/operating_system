/* Prototype
 *
 * #include <stdio.h>
 * int fputc(int c, FILE *stream);
 * int fputs(const char *str, FILE *stream);
 * size_t fwrite(void *buf, size_t size, size_t nr, FILE *stream);
 */

#include <stdio.h>

int main()
{
	FILE *stream;
	int ret;
	size_t nr;
	char buf[20] = "I love Ubuntu.\n";

	stream = fopen("./files/05-file", "a");
	if(!stream)
	{
		perror("fopen");
	}

	ret = fputc('I', stream);
	if(ret == EOF)
	{
		perror("fputc");
	}

	ret = fputs(" love linux.\n", stream);
	if(ret == EOF)
	{
		perror("fputs");
	}

	nr = fwrite(buf, sizeof(char), 14, stream);
	if(nr < 13)
	{
		perror("fwrite");
	}

	return 0;
}
