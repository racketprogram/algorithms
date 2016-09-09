#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s = 0;
int s1 = 0;
int s2 = 0;

int r = 0;
int r1 = 0;
int r2 = 0;

void findMaxSub(int a[], int low, int high)
{
	int i;
	for (i = low; i <= high; i++) {
		if (r > s) {
			s = r;
			s1 = r1;
			s2 = r2;
		}
		if (a[i] > 0) {
			r = r + a[i];
			if (r1 != 0) {
				r2 = i;
			} else {
				r1 = i;
			}
		} else if (a[i] < 0) {
			r = 0;
			r1 = 0;
			r2 = 0;
		}
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

	printf("%d %d %d\n", s1, s2, s);
	
	return 0;
}

