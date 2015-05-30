#include <iostream>
using namespace std;
int main()
{
	double sum_2diagonal(double arry_2d[][100], unsigned int m, unsigned int n);
	int i, j;
	double summ;
	unsigned int x, y;
	double arry[100][100];
	cin >> x >> y;
	for (i = 0; i < x; i++)
		for (j = 0; j < y; j++)
		{
			cin >> arry[i][j];
		}
	summ = sum_2diagonal(arry, x, y);
	cout << summ;
	return 0;
}
double sum_2diagonal(double arry_2d[][100], unsigned int m, unsigned int n)
{
	int n0 = (m>n) ? n : m;
	int i;
	double sum = 0, t = 0;
	for (i = 0; i < n0; i++)
		sum += (arry_2d[i][i]);
	return sum;
}