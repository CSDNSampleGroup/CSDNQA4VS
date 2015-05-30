#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define KMER 5

typedef struct tagDATA{
	__int32 seq;
	struct tagDATA *next;
} DATA, *pDATA;

typedef struct tagHEAD{
	char name;
	void *data;
	struct tagHEAD *nextHead;
} HEAD, *pHEAD;

HEAD *head;
int maxHead = 0;

char TABLE[] =
{
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

HEAD *createHead(char c)
{
	HEAD *h = (HEAD*)malloc(sizeof(HEAD));
	h->name = c;
	h->data = NULL;
	h->nextHead = NULL;

	return h;
}

DATA *createData(int seq)
{
	DATA *d = (DATA*)malloc(sizeof(DATA));
	d->seq = seq;
	d->next = NULL;

	return d;
}
HEAD *incSearch(HEAD *h, char c)
{
	if (h->data == NULL)
	{
		h->data = createHead(c);
		h = (HEAD*)h->data;
		return h; /*FOUND*/
	}
	h = (HEAD*)h->data;
	do
	{
		if (h->name == c)
			return h; /*FOUND*/
		else if (!h->nextHead)
			break;
	} while (h = h->nextHead);
	/* NOT FOUND,ADD*/
	h->nextHead = createHead(c);
	h = h->nextHead;
	return h;
}
void initData(char *filename)
{
	FILE *fn;
	char buff[1024], *b;
	int row = 0;
	int i, j, k, l;
	char c;
	int n;
	HEAD *pos;
	DATA *data, *data0;
	fn = fopen(filename, "r");
	if (fn)
	{
		while (!feof(fn))
		{
			fgets(buff, 1023, fn);
			b = buff;
			n = strlen(buff);
			for (i = 0; i < n - KMER; i++, b++)
			{
				pos = head;
				//生成4个基因组成的基因片（1字节）
				char c;
				for (j = 0; j < KMER; j++)
				{
					c |= TABLE[b[j]];
					c <<= 2;
					if (!((j + 1) % 4 - 1) && j != KMER - 1)
					{
						pos = incSearch(pos, c);
					}/*if*/
				}/*for*/
				pos = incSearch(pos, c);
				data0 = createData((row << 8) | j);
				if (pos->data == NULL)
				{
					pos->data = data0;
				}
				else/*if*/
				{
					data = (DATA*)head->data;
					do
					{
						if (data->next == NULL)
						{
							data->next = data0;
							break;
						}
					} while (data = data->next);
				}/*if*/
			}/*for*/
			row++;
		}/*while(!(feof(fn))*/
		fclose(fn);
	}/*if(fn)*/
}

void main(int argc, char *argv[])
{
	if (argc != 2) return;

	head = (HEAD*)malloc(sizeof(HEAD));
	head->data = NULL;
	head->nextHead = NULL;

	initData(argv[1]);
}