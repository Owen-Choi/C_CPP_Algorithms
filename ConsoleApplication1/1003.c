/*#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
int recur(int index);
int dp[41][2] = { -1, };
int main() {
	int testCase;
	int num;
	scanf("%d", &testCase);
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	while (testCase > 0) {
		testCase--;
		scanf("%d", &num);
		recur(num, 0);
		recur(num, 1);
		printf("%d %d \n", dp[num][0], dp[num][1]);
	}
	return 0;
}

int recur(int index, int second) {
	if (dp[index][second] == -1) {
		dp[index][second] = recur(index - 1, second) + recur(index - 2, second);
	}
	return dp[index];
}*/