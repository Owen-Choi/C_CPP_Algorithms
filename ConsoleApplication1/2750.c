/*#include<stdio.h>

void main() {
	static int arr[1000];
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = N - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d \n", arr[i]);
}*/