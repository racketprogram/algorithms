#include <stdio.h>
#include <stdlib.h>

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

void sort(int a[], int start, int end)
{
	int key = 0, i = 0, j = 0;
	
	for (i = start; i <= end; i++) {
		key = a[i];
		for (j = i - 1; j >=  0 && a[j] > key; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

void divide(int a[], int l,int r)
{
	int m, n;
	n = r - l;
	if (n > 100) {
		m = (l + r) / 2;
		divide(a, l, m);
		divide(a, m + 1, r);
		merge(a, l, m, r);
	} else {
		sort(a, l, r);
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

	divide(nums, 0, 9999);

	for(count = 0; count < 10000; count++) {
		printf("%d ", nums[count]);
	}
	
	return 0;
}

