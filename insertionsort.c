#include <stdio.h>
#include <stdlib.h>

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
	int random_num, count;
	int nums[100];
	for(count = 0; count < 100; count++) {
		nums[count] = rand()/300;
	}
	for(count = 0; count < 100; count++) {
		printf("%d ", nums[count]);
	}
	printf("\n\n\n");

	sort(nums, 99);

	for(count = 0; count < 100; count++) {
		printf("%d ", nums[count]);
	}
	return 0;
}	
