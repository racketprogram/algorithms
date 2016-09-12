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

void findMaxSub(int nums[], int low, int high)
{
	int sum = 0;
	int left = low;
	int right;
	int newpoint;
	int i;
	for (i = low; i <= high; i++) {
		sum = sum + nums[i];
		right = i;
		if (sum > final_sum) {
			max(left, right, sum);
		} else {
			newpoint = right + 1;
			findMaxSub(nums, newpoint, high);
		}
	}
}

int main(void)
{

	int random_num, count;
	int i = 10;
	int nums[10];
	srand(time(NULL));
	for(count = 0; count < 10; count++) {
		nums[count] = rand() % 19 + (-9);
	}
	for(count = 0; count < 10; count++) {
		printf("%d ", nums[count]);
	}
	printf("\n");
	
	findMaxSub(nums, 0,  9);

	printf("%d %d %d\n", final_left, final_right, final_sum);
	
	return 0;
}

