#include <iostream>
using namespace std;
class Point
{
protected:
	int x, y;
};
class Circle :public Point
{
protected:
	double r;
public:
	double area();

};
double Circle::area()
{
	double area;
	cout << "请输入圆的半径r:";
	cin >> r;
	area = 3.14*r*r;
	return area;
}
class Cylinder :public Circle
{
private:
	double h;
public:
	double area();
	double volume();

};
double Cylinder::area()//求圆柱体的表面积 
{
	double barea;
	cout << "请输入圆柱的高:";
	cin >> h;
	barea = 3.14 * 2 * r*h + 3.14*r*r * 2;
	return barea;
}
double Cylinder::volume()//求圆柱体的体积 
{
	double volume;
	volume = 3.14*r*r*h;
	return volume;
}
int main()
{
	Circle cir;
	cout << "圆的面积为：" << cir.area() << endl;
	Cylinder cy;
	cout << "圆柱体的表面积为：" << cy.area() << endl;
	cout << "圆柱体的体积为：" << cy.volume() << endl;
	return 0;
}