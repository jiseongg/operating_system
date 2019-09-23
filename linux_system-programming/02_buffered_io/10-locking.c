/* Prototype
 *
 * #include <stdio.h>
 *
 * void flockfile(FILE *stream);
 * //waits until stream is no longer locked,
 * //bumps the lock count, then acquires the lock
 *
 * void funlockfile(FILE *stream);
 * //dcrements the lock count associated with stream
 *
 * int ftrylockfile(FILE *stream);
 * //stream is locked: do nothing, return nonzero.
 * //stream is unlocked: do flockfile(FILE *stream);
 *
 * there are unlocked counterparts to stdio
 * e.g. int fgetc_unlocked(FILE *stream);
 */
#include <stdio.h>

int main()
{
	FILE *stream;
	stream = fopen("./files/10-file", "w+");

	flockfile(stream);
	fputs("List of treasure:\n", stream);
	fputs("    (1) 500 gold coins\n", stream);
	fputs("    (2) Wonderfully ornate dishware\n", stream);
	funlockfile(stream);

	fclose(stream);
	return 0;
}
