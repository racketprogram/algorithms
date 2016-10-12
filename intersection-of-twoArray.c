#include <stdio.h>
#include <stdlib.h>

void sort(int a[], int length)
{
	int key = 0, i = 0, j = 0;

	for (i = 1; i <= length; i++) {
		key = a[i];
		for (j = i - 1; j >=  0 && a[j] > key; j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

void intersection(int newarray[] ,int nums1[], int nums1Size, int nums2[], int nums2Size) {
    int i, j, k;
    sort(nums1, nums1Size);
    sort(nums2, nums2Size);

    k = 0;
    for (i = 0, j = 0; i <= nums1Size && j <= nums2Size;) {
        if (nums1[i] == nums2[j]) {
            newarray[k] = nums1[i];
            i++;
            j++;
            k++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            i++;
        }
    }
}

int main(void)
{
	int random_num, count;
	int i = 10000;
	int nums1[10000];
    int nums2[10000];
    int nums3[10000];


	for(count = 0; count <10000; count++) {
		nums1[count] = i--;
	}

	i = 10000;
	for(count = 0; count <10000; count++) {
		nums2[count] = i;
		i = i / 2;
	}

	printf("\n\n\n");

	intersection(nums3, nums1, 9999, nums2, 9999);

	for(count = 0; count < 10000; count++) {
		if (nums3[count] != 0) {
			printf("%d ", nums3[count]);
		}
	}
	return 0;
}
