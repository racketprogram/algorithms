#include <stdio.h>
int a[8] = {8,7,5,5,6,6,2,1};

void merge(int a[],int l,int m,int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int i, j, k;
	int left[n1 + 1];
	int right[n2 + 1];

	for (i = 0; i < n1; i++) {
		left[i] = a[l + i];
	}
	left[i] = 88888888;

	for(j = 0; j < n2; j++) {
		right[j] = a[m + 1 + j];
	}
	right[j] = 88888888;

	i = 0;
	j = 0;

	for (k = l; k <= r; k++) {
		if (left[i] > right[j]) {
			a[k] = right[j];
			j++;
		} else {
			a[k] = left[i];
			i++;
		}
	}
}

void divide(int a[],int l,int r)
{
	int m;
	if (l < r) {
		m = (l + r) / 2;
		divide(a, l, m);
		divide(a, m + 1, r);
		merge(a, l, m, r);
	}
}


int main(void)
{
	int i;
	divide(a, 0, 7);
	for (i = 0; i <= 7; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}

