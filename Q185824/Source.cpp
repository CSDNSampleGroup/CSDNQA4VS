#include <stdio.h>
#include <string.h>

void main()
{
	char  r0[256];
	char  r1[256];
	char buff[1024];
	char *b0;
	int  i;

	memset(r0, 0, 256);
	puts("pls input the first string:");
	gets(buff);
	for (b0 = buff; *b0; b0++)
	{
		if (*b0 && !r0[*b0])
			r0[*b0] = 1;
	}
	memset(r1, 0, 256);
	puts("pls input the second string:");
	gets(buff);
	for (b0 = buff; *b0; b0++)
	{
		if (*b0 && !r1[*b0])
			r1[*b0] = 1;
	}

	puts("output:");
	for (i = 0; i < 256; i++)
		if (r0[i] && r1[i])
			putc(i, stdout);
	putc(0x0d, stdout);
}