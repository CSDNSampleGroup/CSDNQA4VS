#include <stdio.h>
int main(void){
	int x, j, i, sum, t, d, count = 0, index;
	int a[10];
	scanf("%d", &x);
	sum = x + 789;
	i = 0;
	while (sum != 0){
		d = sum % 10;
		a[i] = d;
		i++;
		sum = sum / 10;
		count++;
	}
	for (i = 0; i < count; i++){
		index = i;
		for (j = i + 1; j<count; j++)
			if (a[index]>a[j]) index = j;
		t = a[index];
		a[index] = a[i];
		a[i] = t;
	}

	for (i = 0; i < count; i++){
		printf("%d", a[i]);
	}
	printf(" %d", count);

	return 0;
}