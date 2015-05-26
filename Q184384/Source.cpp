#include <stdio.h>
#include <stdlib.h>
#include "Source.h"

//========================================
//
// Cell
//
Cell::Cell(int x0, int y0)
{
	this->x = x0;
	this->y = y0;
	this->animal = NULL;
}
Cell *Cell::nearbyCell(int dir)
{
	int x0 = this->x + Steps[dir].dx;
	int y0 = this->y + Steps[dir].dy;
	if (x0 < 0 || y0 < 0 || x0 >= maxWidth || y0 >= maxHeight)
		return NULL;
	else
	{
		return Status[x0][y0];
	}
}
bool Cell::in(Animal *animal0)
{
	if (this->animal != NULL)
		return false;
	else
	{
		animal0->cell = this;
		this->animal = animal0;
		return true;
	}
}
Animal *Cell::leave()
{
	Animal *theAnimal = this->animal;
	theAnimal->cell = NULL;
	this->animal = NULL;
	return theAnimal;
}
//========================================
//
// Animal
//
Animal::Animal()
{
	this->cell = NULL;
	this->breedTime = 0;
	this->starveTime = 0;

	this->prior = NULL;
	this->next = NULL;
}
bool Animal::breed()
{
	if (this->breedTime >= maxBreedTime)
	{
		for (int i = 0; i < 4; i++)
		{
			Cell *c = this->cell->nearbyCell(i);
			if (c != NULL && c->animal == NULL)
			{
				c->in(this->breedChild());
				this->breedTime = 0;
				return true;
			}
		}
	}
	return false;
}
bool Animal::move()
{
	int dir = rand() % 4;
	Cell *c = this->cell->nearbyCell(dir);
	if (c == NULL)
		return false;
	else if (c->animal == NULL)
	{
		c->in(this->cell->leave());
		return true;
	}
}
void Animal::step()
{
	bool dosth = false;
	this->breedTime++;
	this->starveTime++;

	dosth |= this->breed();
	dosth |= this->eat();
	if (!dosth)
	{
		this->move();
	}

	if (this->maxStarveTime > 0 && this->starveTime >= this->maxStarveTime)
	{
		//starve
		this->cell->leave();
		delete (this);
	}
}
Animal::~Animal()
{
	Animal *t = this->next;
	this->prior->next = t;
	if (t != NULL)
		t->prior = this->prior;
}
//========================================
//
// Ant
//
Ant::Ant() : Animal()
{
	this->type = IsAnt;
	this->maxStarveTime = -1;
	this->maxBreedTime = 3;

	if (Ants != NULL)
	{
		this->prior = Ants;
		this->next = Ants->next;
		if (Ants->next != NULL) Ants->next->prior = this;
		Ants->next = this;
	}
}
Animal *Ant::breedChild()
{
	return new Ant();
}
bool Ant::canEat(AnimalType t)
{
	return false;
}
bool Ant::eat()
{
	return false;
}
//========================================
//
// Doodlebug
//
Doodlebug::Doodlebug() :Animal()
{
	this->type = IsDoodlebug;
	this->maxStarveTime = 3;
	this->maxBreedTime = 8;

	if (DoodleBugs != NULL)
	{
		this->prior = DoodleBugs;
		this->next = DoodleBugs->next;
		if (DoodleBugs->next != NULL) DoodleBugs->next->prior = this;
		DoodleBugs->next = this;
	}
}
Animal *	Doodlebug::breedChild()
{
	return new Doodlebug();
}
bool 	Doodlebug::canEat(AnimalType t)
{
	if (t == IsAnt)
		return true;
	else
		return false;
}
bool 	Doodlebug::eat()
{
	for (int i = 0; i < 4; i++)
	{
		Cell *c = this->cell->nearbyCell(i);
		if (c!=NULL && c->animal != NULL && this->canEat(c->animal->type))
		{
			Animal *theAnimal = c->leave();
			delete(theAnimal);
			this->starveTime = 0;
			return true;
		}
	}
	return false;
}
//========================================
//
// main
//
void randomSet(Animal *animal0)
{
	srand(0);
	int x;
	int y;
	do
	{
		x = rand() % maxWidth;
		y = rand() % maxHeight;
	}
	while (Status[x][y]->animal != NULL);
	Status[x][y]->in(animal0);
}
void  printoutHead()
{
	printf("+");
	for (int i = 0; i < maxWidth; i++)
	{
		printf("=");
	}
	printf("+\n");
}
void printoutDetail(int r)
{
	printf("|");
	for (int i = 0; i < maxWidth; i++)
	{
		if (Status[i][r]->animal == NULL)
			printf(" ");
		else
		{
			switch (Status[i][r]->animal->type)
			{
			case IsAnt:
				printf("O");
				break;
			case IsDoodlebug:
				printf("X");
				break;
			default:
				printf("?");
				break;
			}
		}
	}
	printf("|\n");
}
void printout()
{
	printoutHead();
	for (int i = 0; i < maxHeight; i++)
		printoutDetail(i);
	printoutHead();
}
void main()
{
	int nDoodleBug;
	int nAnt;

	printf("请输入区域宽度：");
	scanf("%d", &maxWidth);
	printf("请输入区域高度：");
	scanf("%d", &maxHeight);
	printf("请输入初始狮蚁数量：");
	scanf("%d", &nDoodleBug);
	printf("请输入初始蚂蚁数量：");
	scanf("%d", &nAnt);

	//maxWidth = 3;
	//maxHeight = 4;
	//nDoodleBug = 2;
	//nAnt = 5;

	Status = new Cell**[maxWidth];
	DoodleBugs = new Doodlebug();
	Ants = new Ant();

	for (int i = 0; i < maxWidth; i++)
	{
		Status[i] = new Cell*[maxHeight];
		for (int j = 0; j < maxHeight; j++)
		{
			Status[i][j] = new Cell(i, j);
		}
	}

	for (int i = 0; i < nDoodleBug; i++)
	{
		randomSet(new Doodlebug());
	}
	for (int i = 0; i < nAnt; i++)
	{
		randomSet(new Ant());
	}

	printout();
	system("pause");
	while (true)
	{
		Animal *a = DoodleBugs->next;
		Animal *a0;
		for ( a0 = (a == NULL ? NULL : a->next); a != NULL; a = a0, a0 = (a == NULL ? NULL : a->next))
			a->step();
		a = Ants->next;
		for ( a0 = (a == NULL ? NULL : a->next); a != NULL; a = a0, a0 = (a == NULL ? NULL : a->next))
			a->step();
		printout();

		system("pause");
	}
}

