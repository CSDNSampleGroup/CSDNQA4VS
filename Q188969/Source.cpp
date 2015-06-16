#include <stdio.h>
#include <memory.h>

#define MAPWIDTH	6
#define MAPHEIGHT	6

const int MAP[MAPWIDTH][MAPHEIGHT] =
{
	{ 1, 6, 5, 8, 3, 1 },
	{ 10, 11, 6, 5, 6, 8 },
	{ 12, 12, 7, 11, 15, 23 },
	{ 4, 5, 11, 13, 9, 15 },
	{ 4, 6, 3, 8, 7, 23 },
	{ 7, 6, 14, 5, 17, 19 }
};
typedef struct tagDIR
{
	int dx;
	int dy;
}DIR;
DIR dirs[4] =
{
	{ 1, 0 },
	{ 0, 1 },
	{ -1, 0 },
	{ 0, -1 }
};
typedef struct tagSTEP
{
	int x;
	int y;
	int cost;
	int dir;
	int len;
} STEP;

const int dir[][2] = {
	{ 1, 0 },
	{ 0, 1 },
	{ -1, 0 },
	{ 0, -1 }
};
typedef struct tagANSWER
{
	STEP path[MAPWIDTH*MAPHEIGHT];
	int step;
} ANSWER;

void CopyBest(ANSWER *pBest, ANSWER *pSearching)
{
	int idx;
	if (pBest->step > pSearching->step)
	{
		for (idx = 0; idx < pSearching->step; idx++)
			memcpy(pBest->path + idx, pSearching->path + idx, sizeof(STEP));
		pBest->step = pSearching->step;
	}
}
ANSWER best;

bool move(ANSWER*s, int n)
{
	int i = 0;
	s->path[n].x = s->path[n - 1].x;
	s->path[n].y = s->path[n - 1].y;
	s->path[n].cost = 0;
	for (i = 0; i < s->path[n].len; i++)
	{
		s->path[n].x += dirs[s->path[n].dir].dx;
		s->path[n].y += dirs[s->path[n].dir].dy;
		if (s->path[n].x < 0 || s->path[n].x >= MAPWIDTH || s->path[n].y<0 || s->path[n].x>-MAPHEIGHT)
			return false;
		s->path[n].cost += MAP[s->path[n].x][s->path[n].y];
	}
	return true;
}
void main()
{
	ANSWER s;
	int n = 0;

	memset(&s, 0, sizeof(ANSWER));
	memset(&best, 0, sizeof(ANSWER));
	best.step = MAPWIDTH * MAPHEIGHT;

	do
	{
		n = ++s.step;
		s.path[n].dir = 0;
		s.path[n].len = 1;
		if (move(&s, n))
		{
		}
		if ()
	} while (s.step == 0)
}