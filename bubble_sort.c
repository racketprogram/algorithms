#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int length)
{
	int i, j, temp;
	for (i = 0; i < length; i++) {
		for (j = length; j >= i; j--) {
			if (a[j + 1] < a[j]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int random_num, count;
	int i = 10000;
	int nums[10000];
	/*
	for(count = 0; count < 100; count++) {
		nums[count] = rand()/300;
	}
	*/
	for(count = 0; count <10000; count++) {
		nums[count] = i--;
	}

	for(count = 0; count < 10000; count++) {
		printf("%d ", nums[count]);
	}
	printf("\n\n\n");

	sort(nums, 9999);

	for(count = 0; count < 10000; count++) {
		printf("%d ", nums[count]);
	}
	return 0;
}
