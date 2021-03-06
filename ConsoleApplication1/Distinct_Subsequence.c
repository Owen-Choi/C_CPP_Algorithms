/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Solve(int **dp, int row, int col, char* A, char* Z);			// this function is for find Subsequences
int FindMax(int** dp, int row, int col);							// this function is for find MaxValue
int main() {
	int testCase;
	scanf("%d", &testCase);
	// dynamically assgined input sentence array(A)
	for (int i = 0; i < testCase; i++) {
		char* A = (char*)malloc(sizeof(char) * 10000);
		char* Z = (char*)malloc(sizeof(char) * 100);
		scanf("%s", A);
		scanf("%s", Z);
		int** dp = (int**)malloc(sizeof(int*) * (strlen(Z) + 1));	//2-dimensional array for memoization
		for (int i = 0; i <= strlen(A); i++) {
			dp[i] = (int*)malloc(sizeof(int) * (strlen(A) + 1));
		}
		Solve(dp, strlen(Z), strlen(A), A, Z);
	}
	return 0;
}
void Solve(int **dp, int row, int col, char* A, char* Z) {

	// Initialize first row values with 1
	// only for fist row, first column values should be 0
	for (int i = 0; i <= col; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= row; i++) {
		for (int k = 0; k <= col; k++) {
			dp[i][k] = 0;
		}
	}

	// update dp value with specific rules :: 
	// if there is same character value between A and Z, then the same index's dp value will be left one + left-cross one
	// if there isn't same character value between A and Z, then dp value will be the bigger one of two values ::
	// :: left one or itself
	for (int i = 1; i <= row; i++) {
		for (int k = 1; k <= col; k++) {
			if (Z[i - 1] == A[k - 1])
				// update dp with left one + left upper-cross one
				dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1];
			else
				// update dp with the bigger one between itself and left one
				dp[i][k] = FindMax(dp, i, k);
		}
	}

	printf("%d \n", dp[row][col]);
}

int FindMax(int **dp, int row, int col) {
	if (dp[row][col] < dp[row][col - 1])
		return dp[row][col - 1];
	else
		return dp[row][col];
}
*/
