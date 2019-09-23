/* Prototype
 *
 * #include <stdio.h>
 * int setvbuf(FILE *stream, char *buf, int mode, size_t size);
 *
 * mode
 * _IONBF: unbuffered. similar to open(), e.g. stderr.
 * _IOLBF: line-buffered. e.g. stdout
 * _IOFBF: block-buffered(full buffering). default.
 */

#include <stdio.h>

int main()
{
	FILE *stream;
	char buf[BUFSIZ];

	stream = fopen("./files/09-file", "r");
	setvbuf(stdout, buf, _IOFBF, BUFSIZ);

	/* must close stream, if local variable is buffer */
	fclose(stream);

	return 0;
}
