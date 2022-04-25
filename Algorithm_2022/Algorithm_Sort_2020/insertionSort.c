#include <stdio.h>

int main() {
	int i, j, temp;
	int array[] = { 1, 10, 5, 8, 7, 6, 9, 3, 2, 4 };
	int len = sizeof(array) / sizeof(int);
	for (i = 0; i < len-1; i++) {
		for (j = i; j >= 0; j--) {
			if (array[j] < array[j + 1]) break;
			temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
		}
	}
	for (i = 0; i < len; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}