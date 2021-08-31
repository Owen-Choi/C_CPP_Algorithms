#include<stdio.h>
#include<stdlib.h>

static int arr[0xF4240];

void quick_Sort(int *arr, int left, int right) {
	if (left >= right)
		return;

	int Pivot = left;
	int Start = Pivot + 1;
	int End = right;
	int temp;

	while (Start <= End) {
		while (arr[Start] <= arr[Pivot] && Start <= right)
			Start++;
		while (arr[End] >= arr[Pivot] && End > left)
			End--;

		if (Start > End) {
			temp = arr[End];
			arr[End] = arr[Pivot];
			arr[Pivot] = temp;
		}
		else {
			temp = arr[Start];
			arr[Start] = arr[End];
			arr[End] = temp;
		}
	}
	quick_Sort(arr, left, End - 1);
	quick_Sort(arr, End + 1, right);
}


int main(void) {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	quick_Sort(arr, 0, N-1);

	for (int i = 0; i < N; i++)
		printf("%d \n", arr[i]);

	return 0;
}
