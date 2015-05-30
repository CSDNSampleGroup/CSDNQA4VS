#include <string>
#include <iostream>
using namespace std;
class Person
{
private:
	char *name;
public:
	Person(char *n1) :name(n1){ strcpy(name, n1); }
	void PrintName() { cout << "The name is:" << name; }
};
class Student :public Person
{
private:
	long int Number;
public:
	Student(char *n2, long int n3) :Person(n2) { Number = n3; }
	void PrintInfo() { cout << "The number is:" << Number << endl; this->PrintName(); }
};
int main()
{
	char ch[] = "уехЩ";
	Person a(ch);
	a.PrintName();
	cout << endl;
	Student b(ch, 142180217);
	b.PrintInfo();
	cout << endl;
	return 0;
}