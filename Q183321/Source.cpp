#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	int i = 0, j, num;
	string in;
	char* arr = new char[200];
	int len = 0;
	while (cin >> in) {
		strcpy(arr, in.c_str());
		len = strlen(arr);
		sort(arr, arr + len);
		for (i = 0; i < len; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}