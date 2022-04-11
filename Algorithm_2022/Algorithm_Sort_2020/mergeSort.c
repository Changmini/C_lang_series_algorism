#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *sorted; // ���Ĺ迭�� ��������

void merge(int* a, int m, int middle, int n) {
	int i = m;
	int j = middle + 1;
	int k = m;

	 do {
		 // �迭 1,2�� �����͸� �˻��Ͽ� ���� �ͺ��� ����
		if (a[i] <= a[j] && i <= middle
			// ����(�迭1 or �迭2)���� �˻簡 ���� ������ �Ǹ�,
			// ���� �ٸ� ����(�迭1 or �迭2)�� ���ڵ��� ����
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