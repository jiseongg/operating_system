/* Prototype
 *
 * #include <stdio.h>
 * int fgetc(FILE *stream);
 * int ungetc(int c, FILE *stream);
 * char *fgets(char *str, int size, FILE *stream);
 */

#include <stdio.h>

int main()
{
	FILE* stream;
	int c, ret;
	char buf[100];

	stream = fopen("./files/03-file", "r");
	if(stream == NULL)
	{
		perror("fopen");
	}

	/* read one charactor */
	c = fgetc(stream);
	/* c must be int to detect error */
	if(c == EOF)
	{
		perror("fgetc");
	}
	else
	{
		printf("c = %c\n", (char) c);
	}

	/* read untill 100 - 1 and add '\0'
	 * read stops after an EOF or '\n'
	 */
	if(!fgets(buf, 100, stream))
	{
		perror("fgets");
	}
	printf("buf: %s\n", buf);

	fclose(stream);
	return 0;
}
