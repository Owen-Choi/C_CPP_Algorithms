#include<stdio.h>
#include<stdlib.h>
static int arr[1001][2];				//arr[index][0] = weight, arr[index][1] = IQ
static int iter = 0;
static int ForIndex[1001][3];			//ForIndex[index][0] = weight, ForIndex[index][1] = IQ, ForIndex[index][2] = index(original)
static int indexes[1001];				//For store indexes in the process of Dynamic Programming
static int dp[1001];					//For identifying the longest subsequence and also used as condition
void bubble();							//sorting func
void swap(int index1, int index2);
void Elephant();						//dp func
int main() {

	FILE *filePointer;
	filePointer = fopen("C:\\Users\\oldst\\Desktop\\Input3.txt", "r");
	if (filePointer == NULL) {
		printf("Cannot find any Files");
		exit(1);
	}
	int temp_Weight, temp_IQ;
	while (fscanf(filePointer, "%d %d\n", &temp_Weight, &temp_IQ) != EOF) {
		arr[iter][0] = ForIndex[iter][0] = temp_Weight;
		arr[iter][1] = ForIndex[iter][1] = temp_IQ;
		ForIndex[iter][2] = iter++;
	}
	bubble();
	Elephant();
	int MAX = -1;
	for (int i = 0; i < iter; i++) {
		if (dp[i] > MAX)
			MAX = dp[i];
	}
	printf("%d\n", MAX);
	for (int i = 0; i < MAX; i++) {
		for (int k = 0; k < iter; k++) {
			if (arr[indexes[i]][0] == ForIndex[k][0] && arr[indexes[i]][1] == ForIndex[k][1]) {
				printf("%d\n", ForIndex[k][2] + 1);
				break;
			}
		}
	}
	return 0;
}

void bubble() {
	for (int i = 0; i < iter; i++) {
		for (int k = 0; k < iter - 1; k++) {
			if (arr[k][0] > arr[k+1][0]) {
				swap(k, k+1);
			}
		}
	}
	// for sorting elephant's IQ values with ascending order, which there is some elephant with the same Weight value
	for (int i = 0; i < iter; i++) {
		for (int k = 0; k < iter - 1; k++) {
			if (arr[k][0] == arr[k + 1][0] && arr[k][1] > arr[k + 1][1])
				swap(k, k + 1);
		}
	}
}
void swap(int index1, int index2) {
	int temp1 = arr[index1][0];
	int temp2 = arr[index1][1];
	arr[index1][0] = arr[index2][0];
	arr[index1][1] = arr[index2][1];
	arr[index2][0] = temp1;
	arr[index2][1] = temp2;
}


void Elephant() {
	int tempIter = 0;
	for (int i = 0; i < iter; i++)
		dp[i] = 1;
	for (int i = 1; i < iter; i++) {
		for (int k = 0; k < i; k++) {
			if (arr[i][0] > arr[k][0] && arr[i][1] < arr[k][1] && dp[i] < dp[k] + 1) {
				dp[i] = dp[k] + 1;
				if (tempIter == 0) {
					indexes[tempIter++] = k; indexes[tempIter++] = i;
				}
				else if (indexes[tempIter - 1] == k)
					indexes[tempIter++] = i;
			}
		}
	}
}
