#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int length)
{
	int key = 0, i = 0, j = 0;
	int temp, temp1;
	for (i = 0; i <= length; i++) {
		key = a[i];
		for (j = i; j <= length; j++) {
			if (a[j] < key) {
				key = a[j];
				temp1 = j;
			}
		}
		temp = a[i];
		a[i] = key;
		a[temp1] = temp;
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
