#include <iostream>
using namespace std;
class Shape
{
public:
	virtual int Area() const = 0;
};
class Rectangle : public Shape{
protected:
	int length, width;
public:
	Rectangle(int l = 0, int w = 0)
	{
		length = l;
		width = w;
	}
	virtual int Area()const
	{
		return length*width;
	}
};
int main()
{
	Shape *p;
	Rectangle r(3, 5);
	p = &r;
	cout<<p->Area() << endl;
	return 0;
}