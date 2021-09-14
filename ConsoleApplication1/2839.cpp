#include<iostream>

using namespace std;
int Min(int a, int b);
// basic knapsack Algorithm ::
int main() {
	int Value;
	cin >> Value;
	int result = 0;
	int Five = Value / 5;
	int temp;
	while (Five >= 0) {
		temp = Value - Five * 5;
		if (temp % 3 == 0) {
			result = Five + temp / 3;
			break;
		}
		if (temp % 3 != 0) {
			Five--;
		}
	}
	if (Five < 0)
		cout << -1;
	else
		cout << result;

	return 0;
}
	