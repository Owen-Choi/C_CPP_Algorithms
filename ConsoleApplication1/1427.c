/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
static int N;

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return -1;
	if (num1 < num2)
		return 1;
	else
		return 0;
}

int main() {
	scanf("%d", &N);
	char s[11];
	int arr[11];
	sprintf(s, "%d", N);
	for (int i = 0; i < strlen(s); i++) {
		arr[i] = s[i] - '0';
	}
	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);
	for (int i = 0; i < strlen(s); i++)
		printf("%d", arr[i]);
	return 0;
}*/