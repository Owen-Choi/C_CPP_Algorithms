/*#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	const int size = 1e5;
	int n;
	cin >> n;
	pair<int, int> arr[size];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;		//sort는 first를 기준으로 되기 때문에 second를 먼저 입력받음.
	}
	sort(arr, arr + n);

	int result = 0;
	int prev = 0;
	int tempStart, tempFinish;

	for (int i = 0; i < n; i++) {
		tempStart = arr[i].second;
		tempFinish = arr[i].first;
		if (tempStart >= prev) {
			prev = tempFinish;
			result++;
		}
	}

	cout << result << endl;
}*/