#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Solve(int **dp, int row, int col, char* A, char* Z);
int FindMax(int** dp, int row, int col);
int main() {
	int testCase;
	scanf("%d", &testCase);
	// dynamically assgined input sentence array(A)
	for (int i = 0; i < testCase; i++) {
		char* A = (char*)malloc(sizeof(char) * 10000);
		char* Z = (char*)malloc(sizeof(char) * 100);
		scanf("%s", A);
		scanf("%s", Z);
		int** dp = (int**)malloc(sizeof(int*) * (strlen(Z) + 1));
		for (int i = 0; i <= strlen(A); i++) {
			dp[i] = (int*)malloc(sizeof(int) * (strlen(A) + 1));
		}
		Solve(dp, strlen(Z), strlen(A), A, Z);
	}
	return 0;
}
void Solve(int **dp, int row, int col, char* A, char* Z) {

	for (int i = 0; i <= col; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= row; i++) {
		for (int k = 0; k <= col; k++) {
			dp[i][k] = 0;
		}
	}

	for (int i = 1; i <= row; i++) {
		for (int k = 1; k <= col; k++) {
			if (Z[i - 1] == A[k - 1])
				dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1];
			else
				dp[i][k] = FindMax(dp, i, k);
		}
	}
	printf("%d", dp[row][col]);
}

int FindMax(int **dp, int row, int col) {
	if (dp[row][col] < dp[row][col - 1])
		return dp[row][col - 1];
	else
		return dp[row][col];
}

