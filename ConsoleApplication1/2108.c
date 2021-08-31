#include<stdio.h>

static int arr[8002];
static int MAX = -1;

void Average();
void Middle();
void MostHave();
void Range();

int main() {
	int N, temp;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (temp < 0)
			arr[temp * -1];
		else
			arr[temp + 4000];
		if (MAX < temp + 4000)
			MAX = temp + 4000;
	}

	Average();

	return 0;
}


void Average() {
	int sum = 0;
	for (int i = 0; i < MAX; i++)
		sum += arr[i]*i;
	printf("%d \n", sum / MAX);
}

void Middle(int size) {

}