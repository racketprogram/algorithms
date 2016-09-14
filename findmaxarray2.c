#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int final_left = 0;
int final_right = 0;
int final_sum = 0;

void findMaxSub(int nums[], int low, int high)
{
	int sum_record[high - low];
	int right_record[high - low];
	int left_record[high - low];

	int sum = nums[low];
	sum_record[low] = nums[low];
	int left = low;
	int right = low;

	int i;
	for (i = low + 1; i <= high; i++) {
		if (sum > 0) {
			right = i;
			sum += nums[i];
			sum_record[i] = sum;
			left_record[i] = left;
			right_record[i] = right;
		} else {
			sum_record[i] = nums[i];
			sum = nums[i];
			left = i;
			right = i;
			left_record[i] = left;
			right_record[i] = right;
		}
	}
	sum = sum_record[low];
	for (i = low + 1; i <= high; i++) {
		if (sum_record[i] > sum) {
			final_left = left_record[i];
			final_right = right_record[i];
			final_sum = sum_record[i];
			sum = sum_record[i];
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

