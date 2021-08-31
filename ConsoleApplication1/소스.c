#include<stdio.h>
#define max(a,b) (a > b) ? a : b;
#define min(a,b) (a < b) ? a : b;

int main() {
	int arr[0xF4240];
	int N;
	printf("hello there");
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int MAX = -1;
	int MIN = 0xF4240 + 1;

	for (int i = 0; i < N; i++) {
		MAX = max(MAX, arr[i]);
		MIN = min(MIN, arr[i]);
	}

	printf("%d %d", MIN, MAX);
	return;
}