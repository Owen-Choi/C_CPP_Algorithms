#include<stdio.h>


static int arr[10001];
static int MAX = -1;
int main() {
	int N;
	scanf("%d", &N);
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr[temp]++;
		if (temp > MAX)
			MAX = temp;
	}
	int i, k;
	for (i = 0; i <= MAX; i++) {
		for (k = arr[i]; k > 0; k--)
			printf("%d \n", i);
	}
	return 0;
}