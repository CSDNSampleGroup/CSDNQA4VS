#ifndef __SOURCE_H__
#define __SOURCE_H__

struct Step
{
	int dx;
	int dy;
};

enum AnimalType
{
	IsAnt,
	IsDoodlebug
};

class Animal;
class Cell
{
public:
	int x;
	int y;
	Animal *animal;

public:
	Cell(int x0, int y0);
	Cell *nearbyCell(int dir);
	bool in(Animal *animal0);
	Animal *leave();
};

class Animal
{
protected:
	int maxBreedTime;
	int breedTime;
	int maxStarveTime;
	int starveTime;
public:
	AnimalType type;
	Animal *next;
	Animal *prior;
public:
	Animal();
	virtual ~Animal();

public://virtual
	virtual Animal *breedChild() = 0;
	virtual bool canEat(AnimalType animal) = 0;
	virtual bool eat() = 0;

public:
	Cell *cell;
	bool breed();
	bool move();
	void step();
};

class Ant :public Animal
{
public:
	Ant() ;
public:
	virtual Animal *breedChild();
	virtual bool canEat(AnimalType t);
	virtual bool eat();
};

class Doodlebug :public Animal
{
public:
	Doodlebug() ;
public:
	virtual Animal *breedChild();
	virtual bool canEat(AnimalType t);
	virtual bool eat();
};


Step Steps[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int maxWidth;
int maxHeight;
Cell ***Status;
Animal *DoodleBugs;
Animal *Ants;

#endif //__SOURCE_H__