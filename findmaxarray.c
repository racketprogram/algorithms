#include <stdio.h>
int a[20] = {-20,-19,-18,-17,16,15,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,14,13,-12,11};

int final_left = 0;
int final_right = 0;
int final_sum = 0;

void max(int l, int r, int s)
{
	if (s > final_sum) {
		final_sum = s;
		final_left = l;
		final_right = r;
	}
}

void findMaxCrossSub(int a[], int low, int mid, int high)
{
	int sum;
	int left_sum = -1000;
	int right_sum = -1000;
	int i;
	int j;
	int max_left;
	int max_right;
	
	sum = 0;
	for (i = mid; i >= low; i--) {
		sum = sum + a[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;		
		}
	}
	
	sum = 0;
	for (j = mid + 1; j <= high; j++) {
		sum = sum + a[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	
	max(max_left, max_right, right_sum + left_sum);
}

void findMaxSub(int a[], int low, int high)
{
	int mid;
	
	if (low == high) {
		max(low, high, a[low]);
	} else {
		mid = (low + high) / 2;		
		findMaxSub(a, low, mid);
		findMaxSub(a, mid + 1, high);
		findMaxCrossSub(a, low, mid, high);
	}
}


int main(void)
{
	findMaxSub(a, 0, 19);

	printf("%d %d %d\n", final_left, final_right, final_sum);
	
	return 0;
}

