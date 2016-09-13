#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int final_left = 0;
int final_right = 0;
int final_sum = 0;

void findMaxSub(int nums[], int low, int high)
{
	int sums[high - low];
	int rights[high - low];
	int lefts[high - low];

	int sum = nums[0];
	int sum2 = sum;
	sums[low] = sum;
	int left = low;
	int right = low;
	int i;
	for (i = low + 1; i <= high; i++) {
		if (sum > 0) {
			right = i;
			sum += nums[i];
			if (sum > sum2) {
				sums[i] = sum;
				lefts[i] = left;
				rights[i] = right;
				sum2 = sum;
			} else {
				sums[i] = 0;
				lefts[i] = left;
				rights[i] = right;
			}
		} else {
			sums[i] = nums[i];
			sum = nums[i];
			left = i;
			right = i;
			lefts[i] = left;
			rights[i] = right;
		}
	}
	sum = sums[low];
	for (i = low + 1; i <= high; i++) {
		if (sums[i] > sum) {
			final_left = lefts[i];
			final_right = rights[i];
			final_sum = sums[i];
			sum = sums[i];
		}
	}
}

int main(void)
{

	int random_num, count;
	int i = 10000;
	int nums[10000];
	srand(time(NULL));
	for(count = 0; count < 10000; count++) {
		nums[count] = rand() % 19 + (-9);
	}
	for(count = 0; count < 10000; count++) {
		printf("%d ", nums[count]);
	}
	printf("\n");
	
	findMaxSub(nums, 0,  9999);

	printf("%d %d %d\n", final_left, final_right, final_sum);
	
	return 0;
}

