#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	if (argc < 2)return;
	char *filename = argv[1];

	FILE *fn;
	int i = 0,j;
	int a[10], *a0 = a;
	int b[10], *b0 = b;
	double c[10], *c0 = c;
	int a1, b1; double c1;
	if (fn = fopen(filename, "r"))
	{
		while (!feof(fn))
		{
			fscanf(fn, "%d %d %lf", a0++, b0++, c0++);
			if (++i >= 10)
				break;
		}
		fclose(fn);
	}

	printf("Column1\n");
	for (j = 0; j < i; j++)
		printf("A[%d]=%d\n", j, a[j]);
	printf("Column2\n");
	for (j = 0; j < i; j++)
		printf("B[%d]=%d\n", j, b[j]);
	printf("Column3\n");
	for (j = 0; j < i; j++)
		printf("C[%d]=%lf\n", j, c[j]);


	system("pause");
}