/*#include<stdio.h>
#include<stdlib.h>

void HeapSort(int *arr, int size);

int main() {
	int N;
	scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * 1000000);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	HeapSort(arr, N);

	return 0;
}

void HeapSort(int* arr, int size) {
	int parent, child;
	// 최초의 heap tree 생성
	for (int i = 1; i < size; i++) {
		child = i;
		while (child > 0) {

		}
	}
}*/