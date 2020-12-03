/* Prototype
 *
 * #include <stdio.h>
 * 
 * int ferror(FILE *stream);
 * //return nonzero: error indicator is set
 *
 * int feof(FILE *stream);
 * //return nonzero: EOF indicator is set
 *
 * void clearerr(FILE *stream);
 * //clears error, EOF indicators and never fail
 *
 * int fileno(FILE *stream);
 * //returns the file descriptor associated with the stream
 */


/* developers need to differentiate EOF, error */
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *stream;
	char buf[10];
	stream = fopen("./files/08-file", "r");
	fseek(stream, 0, SEEK_SET);
	fread(buf, 10, 1, stream);
	if(ferror(stream))
	{
		printf("read error: %s\n", strerror(ferror(stream)));
		return -1;
	}
	else if(feof(stream))
	{
		printf("end of files...\n");
	}

	fclose(stream);
	return 0;
}
