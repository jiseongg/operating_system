/* Prototype
 *
 * #include <stdio.h>
 * int fseek(FILE *stream, long offset, int whence);
 * long ftell(FILE *stream)
 *
 * whence: SEEK_SET, SEEK_CUR, SEEK_END
 * fseek success returns 0, failure returns -1 and sets errno.
 * ftell failure returns -1 and sets errno.
 *
 * // for non unix system 
 * int fsetpos(File *stream, fpos_t *pos);
 * int fgetpos(FILE *stream, fpos_t *pos);
 */

#include <stdio.h>

int main()
{
	FILE *stream;
	long size;
	char str[1000];

	stream = fopen("./files/07-file", "r");
	/* file contents: 0123456789abcdefghij */

	printf("%s", fgets(str, 1000, stream)); //print all
	
	fseek(stream, 10, SEEK_SET);
	printf("%s", fgets(str, 1000, stream)); //print abcdefghij

	fseek(stream, 3, SEEK_SET);
	fseek(stream, 7, SEEK_CUR);
	printf("%s", fgets(str, 1000, stream)); //print abcdefghij

	fseek(stream, -3, SEEK_END);
	printf("%s\n", fgets(str, 1000, stream)); //print hij


	/* get file size with ftell */
	fseek(stream, 0, SEEK_END);
	size = ftell(stream);

	printf("%d\n", fgets(str, 1, stream)[0]);
	/* \0 will be printed */

	printf("%ld\n", size);
	fclose(stream);

	return 0;
}
