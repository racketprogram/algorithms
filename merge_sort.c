#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[],int l,int m,int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int i, j, k;
	int left[n1 + 1];
	int right[n2 + 1];

	for (i = 0; i < n1; i++) {
		left[i] = a[l + i];
	}
	left[i] = 88888888;

	for(j = 0; j < n2; j++) {
		right[j] = a[m + 1 + j];
	}
	right[j] = 88888888;

	i = 0;
	j = 0;

	for (k = l; k <= r; k++) {
		if (left[i] > right[j]) {
			a[k] = right[j];
			j++;
		} else {
			a[k] = left[i];
			i++;
		}
	}
}

void divide(int a[],int l,int r)
{
	int m;
	if (l < r) {
		m = (l + r) / 2;
		divide(a, l, m);
		divide(a, m + 1, r);
		merge(a, l, m, r);
	}
}


int main(void)
{
	int random_num, count;
	int i = 10000;
	int nums[10000];
	srand(time(NULL));
	for(count = 0; count < 10000; count++) {
		nums[count] = rand();
	}
	/*
	for(count = 0; count <10000; count++) {
		nums[count] = i--;
	}
	*/

	for(count = 0; count < 10000; count++) {
		printf("%d ", nums[count]);
	}
	printf("\n\n\n");

	divide(nums, 0, 9999);

	for(count = 0; count < 10000; count++) {
		printf("%d ", nums[count]);
	}

	return 0;
}
