#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[100];

int max(int x, int y)
{
	if(x > y) {
		return x;
	} else {
		return y;
	}
}

int cutRod(int p[], int n)
{
	if (a[n] >= 0) {
		return a[n];
	}

	int q;
	if (n == 0) {
		q = 0;
	} else {
		q = -1000;
		for (int i = 0; i <= n; i++) {
			int x = p[i] + cutRod(p, n-i-1);
			q = max(q, x);
		}
	}
	a[n] = q;
	return q;
}


int main(void)
{
	int nums[10] = { 1,1,1,1,1,1,1,1,1,1 };
	/*
	int nums[10];
	srand(time(NULL));
	for(i = 0; i < 10; i++) {
		nums[i] = rand() / 10000;
	}
	*/
	for(int i = 0; i < 100; i++) {
		a[i] = -100;
		printf("%d ", a[i]);
	}
	printf("\n\n\n");

	for(int i = 0; i < 10; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n\n\n");

	int result = cutRod(nums, 15);
	printf("%d\n", result);

	return 0;
}
