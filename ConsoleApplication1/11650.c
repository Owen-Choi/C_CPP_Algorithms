#include<stdio.h>
#include<stdlib.h>

int main() {
	int testCase;
	scanf("%d", &testCase);
	int **arr = malloc(sizeof(int*) * testCase);

	for (int i = 0; i < testCase; i++) {
		arr[i] = malloc(sizeof(int) * 2);		//이차원배열 동적할당
	}

	for (int i = 0; i < testCase; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (int i = 1; i < testCase; i++) {
		for (int k = i-1; k >= 0; k--) {
			if (arr[i][0] < arr[k][0]) {
				int temp = arr[i];
				arr[i] = arr[k];
				arr[k] = temp;
			}
			else if (arr[i][0] == arr[k][0]) {
				if (arr[i][1] > arr[k][1]) {
					int temp = arr[i];
					arr[i] = arr[k];
					arr[k] = temp;
				}
			}
		}
	}

	for (int i = 1; i < testCase; i++) {
		for (int k = i - 1; k >= 0; k--) {
			if (arr[k][0] == arr[i][0]) {
				if (arr[k][1] > arr[i][1]) {
					int temp = arr[k];
					arr[k] = arr[i];
					arr[i] = temp;
				}
			}
		}
	}


	for (int i = 0; i < testCase; i++)
		printf("%d %d \n", arr[i][0], arr[i][1]);

	return 0;
}
