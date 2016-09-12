#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    unsigned left;
    unsigned right;
    int sum;
} max_subarray;

max_subarray find_maximum_subarray(int A[], unsigned low, unsigned high) {
    max_subarray suffixes[high - low];

    suffixes[0].left = low;
    suffixes[0].right = low + 1;
    suffixes[0].sum = A[low];

    for (int i = low + 1; i < high; i++) {
        if (suffixes[i - 1].sum < 0) {
            suffixes[i].left = i;
            suffixes[i].right = i + 1;
            suffixes[i].sum = A[i];
        } else {
            max_subarray *previous = &suffixes[i - 1];
            suffixes[i].left = previous->left;
            suffixes[i].right = i + 1;
            suffixes[i].sum = previous->sum + A[i];
        }
    }

    max_subarray *max = &suffixes[0];

    for (int i = low + 1; i < high; i++) {
        if (max->sum < suffixes[i].sum) {
            max = &suffixes[i];
        }
    }

    return *max;
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
	
	max_subarray test = find_maximum_subarray(nums, 0, 99);

	printf("%d %d %d\n", test.left, test.right, test.sum);
	
	return 0;
}
