#include<stdio.h>

#define INF 1000000
#define size 4

int arr[size][size] = {
	{0,5,INF,8},
	{7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0}
};

int main() {

	int result[size][size];
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			result[i][k] = arr[i][k];
		}
	}

	for (int pivot = 0; pivot < size; pivot++) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (result[i][j] > result[i][pivot] + result[pivot][j])
					result[i][j] = result[i][pivot] + result[pivot][j];
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++)
			printf("%d ", result[i][k]);
		printf("\n");
	}
	return 0;
}