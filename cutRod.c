#include <stdio.h>

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
	int q, i, x;
	if (n == 0) {
		return 0;
	}
	q = -10000;
	for (i = 0; i <= n; i++) {
		x = p[i] + cutRod(p, n-i-1);
		q = max(q, x);
	}
	return q;
}


int main(void)
{

	int nums[10] = { 1,1,1,1,10,1,1,39,1,39 };
	for(int count = 0; count < 10; count++) {
		printf("%d ", nums[count]);
	}
	printf("\n\n\n");

	int result = cutRod(nums, 10);
	printf("%d\n", result);

	return 0;
}
