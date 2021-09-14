#include<iostream>

using namespace std;
int Min(int a, int b);
// basic knapsack Algorithm ::
int main() {
	int Value;
	cin >> Value;
	int Increasing3 = 1, Increasing5 = 1;
	// dynamically allocated :: 
	int** dp = new int*[3]();
	for (int i = 0; i < 3; i++)
		dp[i] = new int[Value + 1]();

	for (int i = 1; i < 3; i++) {
		for (int k = 1; k <= Value; k++) {
			if (i == 1) {
				if (k % 5 == 0) {
					for(int j = k; j <=Value; j++)
						dp[i][j] = Increasing5;
					Increasing5++;
				}
			}
			else {
				if (k % 3 == 0) {
					if (dp[i - 1][k] != 0) {
						dp[i][k] = Min(dp[i][k-1] + 1, Increasing3++);
						Increasing3 = dp[i][k] + 1;
					}
					else
						dp[i][k] = Increasing3++;
				}
				else
					dp[i][k] = dp[i-1][k];
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k <= Value; k++) {
			cout << dp[i][k] << " ";
		}
		cout << "\n";
	}

	if (dp[2][Value] == 0)
		cout << -1;
	else
		cout << dp[2][Value];
	return 0;
}

int Min(int a, int b) {
	return a < b ? a : b;
}