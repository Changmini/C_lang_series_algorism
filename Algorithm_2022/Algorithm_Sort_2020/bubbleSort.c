#include <stdio.h>

int main(void) {
	int i, j, temp;
	int array[] = { 1, 10, 5, 8, 7, 6, 9, 3, 2, 4 };
	int len = sizeof(array) / sizeof(int);
	for (i = len; i > 0; i--) {
		for (j = 0; j < i-1; j++) {
			if (array[j] > array[j+1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}