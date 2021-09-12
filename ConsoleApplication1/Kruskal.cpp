#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int getParent(int set[], int index);
void UnionParent(int set[], int first, int second);
int find(int set[], int a, int b);

class Edge {
public:
	int node[2];
	int distance;
	Edge(int Start, int End, int distance) {
		node[0] = Start;
		node[1] = End;
		this->distance = distance;
	}
	// used for sorting
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};


int main() {

	int n = 7, m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	
	sort(v.begin(), v.end());
	
	int* set = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			UnionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	cout << sum << "\n";
	return 0;
}

int getParent(int set[], int index) {
	if (set[index] == index) return index;
	return set[index] = getParent(set, set[index]);
}

void UnionParent(int set[], int first, int second) {
	first =  getParent(set, first);
	second = getParent(set, second);
	if (first < second) set[second] = first;
	else set[first] = second;
}

int find(int set[], int first, int second) {
	first = getParent(set, first);
	second = getParent(set, second);
	if (first == second) return 1;
	else return 0;
}

