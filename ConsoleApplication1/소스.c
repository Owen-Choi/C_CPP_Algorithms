#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int arr[100][2];
	int testCase;
	int temp[2] = { 0,0 };
	const int START = 0;
	const int FINISH = 1;
	scanf("%d", &testCase);
	char string[255];
	int iter = 0;
	int i = 0;
	while (testCase > 0) {
		testCase--;
		scanf("%s", string);
		int tempIter = 0;
		char* ptr1 = strtok(string, " ");
		while (ptr1 != NULL && tempIter < 2) {
			char* ptr2 = strtok(ptr1,":");
			iter = 0;
			while (iter < 2 && ptr2 != NULL) {
				temp[iter++] = atoi(ptr2);
				ptr2 = strtok(NULL, ":");
			}
			arr[i][tempIter++] = temp[0] * 100 + temp[1];
			ptr1 = strtok(NULL, " ");
		}
		i++;
	}
	printf("%d    %d", arr[0][0], arr[0][1]);
#pragma warning (disable: 4996)
}