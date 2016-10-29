#include <stdio.h>
#include <math.h>

int main(void)
{
	int i;
	float sum = 0.0;
	for (i = 1; ; i++) {
		float j = (float)i;
		sum = sum + ((j * j) / (float)pow(2, i));
		

		printf("%f\n", j);
	}
	return 0;
}
