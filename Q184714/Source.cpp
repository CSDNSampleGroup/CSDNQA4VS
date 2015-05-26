#include<stdio.h>
#include<stdlib.h>
void Merglist(int a[], int b[], int c[], int m, int n){
	int i, j, k;
	i = 0; j = 0; k = 0;
	while (i<m&&j<n){
		if (a[i] <= b[j]){
			c[k++] = a[i];
			++i;
		}
		else{
			c[k++] = b[j];
			++j;
		}
	}
	while (i<m){
		c[k++] = a[i];
		i++;
	}
	while (j<n){
		c[k++] = b[j];
		j++;
	}
}
int main(){
	int a[100];
	int b[100];
	int c[200];
	int i, j, n, m;
	scanf("%d", &m);
	for (i = 0; i<m; i++){
		scanf("%d", &a[i]);
	}
	scanf("%*c");
	scanf("%d", &n);
	for (j = 0; j<n; j++){
		scanf("%d", &b[j]);
	}

	Merglist(a, b, c, m, n);
	for (i = 0; i<m + n; i++){
		if (i == 0){
			printf("%d", c[i]);
		}
		else
			printf(" %d", c[i]);
	}
	return 0;
}