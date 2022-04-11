#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *sorted; // 정렬배열는 전역변수

void merge(int* a, int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

	 do {
		 // 배열 1,2에 데이터를 검사하여 작은 것부터 정렬
		if (a[i] <= a[j] && i <= middle
			// 한쪽(배열1 or 배열2)부터 검사가 먼저 끝나게 되면,
			// 남은 다른 한쪽(배열1 or 배열2)의 숫자들을 정렬
			|| i <= middle && j > n) { 
			sorted[k] = a[i];
			i++;
		}
		else if (a[i] >= a[j] && j <= n 
			|| j <= n && i > middle) {
			sorted[k] = a[j];
			j++;
		}
		k++;
	 } while (i <= middle || j <= n);

	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
		printf("=%d ", sorted[t]);
	}
	printf("\n");
}

void mergeSort(int a[], int m, int n) {
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main() {
	int* array;
	int number=0;

	scanf("%d",&number);
	sorted = (int*)malloc(sizeof(int) * number);
	array = (int*)malloc(sizeof(int) * number);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < number; i++) {
		array[i] = rand()%10;
		printf("%d", array[i]);
	}
	printf("\n");

	mergeSort(array, 0, number - 1);

	for (int i = 0; i < number; i++)
	{
		printf("%d ", array[i]);
	}
}