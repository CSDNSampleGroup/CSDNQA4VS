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
	cout << "������Բ�İ뾶r:";
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
double Cylinder::area()//��Բ����ı���� 
{
	double barea;
	cout << "������Բ���ĸ�:";
	cin >> h;
	barea = 3.14 * 2 * r*h + 3.14*r*r * 2;
	return barea;
}
double Cylinder::volume()//��Բ�������� 
{
	double volume;
	volume = 3.14*r*r*h;
	return volume;
}
int main()
{
	Circle cir;
	cout << "Բ�����Ϊ��" << cir.area() << endl;
	Cylinder cy;
	cout << "Բ����ı����Ϊ��" << cy.area() << endl;
	cout << "Բ��������Ϊ��" << cy.volume() << endl;
	return 0;
}