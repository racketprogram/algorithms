#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int final_left = 0;
int final_right = 0;
int final_sum = 0;

void max(int left, int right, int sum)
{
	if (sum > final_sum) {
		final_sum = sum;
		final_left = left;
		final_right = right;
	}
}

void findMaxCrossSub(int a[], int low, int mid, int high)
{
	int sum;
	int left_sum = -1000000;
	int right_sum = -1000000;
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

	int random_num, count;
	int i = 100;
	int nums[100];
	srand(time(NULL));
	for(count = 0; count < 100; count++) {
		nums[count] = rand() % 19 + (-9);
	}
	for(count = 0; count < 100; count++) {
		printf("%d ", nums[count]);
	}
	printf("\n");
	
	findMaxSub(nums, 0, 99);

	printf("%d %d %d\n", final_left, final_right, final_sum);
	
	return 0;
}

