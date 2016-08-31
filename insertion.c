#include <stdio.h>
#include <stdlib.h>

int a[10] = {5,6,7,8,9,1,2,3,4,0};

void sort(int a[], int length)
{
	int key = 0, i = 0, j = 0;
	
	for (i = 1; i <= length; i++) {
		key = a[i];
		for (j = i - 1; j >=  0 && a[j] > key; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int main(void)
{
	int i = 0;
	for (i = 0; i <= 9; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	sort(a);
	for (i = 0; i <= 9; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}	
