#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
int testcase;
struct person {
	int index;
	int age;
	char name[20];
};

void Solve(struct person *d, struct person *sort);
void mergeSort(struct person* d,struct person *sort, int start, int finish);
void merge(struct person* d, struct person *sort,int start, int finish, int pivot);
int main() {

	cin >> testcase;
	struct person* d;
	struct person* sort;
	d = (struct person*)malloc(sizeof(struct person) * testcase);
	for (int i = 0; i < testcase; i++) {
		cin >> d[i].age >> d[i].name;
		d[i].index = i;

	}
	sort = (struct person*)malloc(sizeof(struct person) * testcase);
	Solve(d, sort);
	return 0;
}

// try to use advanced-sorting algorithm
void Solve(struct person *d, struct person *sort) {
	mergeSort(d, sort, 0, testcase - 1);
	for (int i = 0; i < testcase; i++) {
		cout << sort[i].age << " " << sort[i].name;
		cout << "\n";
	}
}

void mergeSort(struct person* d, struct person *sort, int start, int finish) {
	int pivot;
	if (start < finish) {
		pivot = (start + finish) / 2;
		mergeSort(d, sort, start, pivot);
		mergeSort(d, sort, pivot + 1, finish);
		merge(d, sort, start, finish, pivot);
	}
}

void merge(struct person* d,struct person *sort, int start, int finish, int pivot) {
	int Firststart = start, LaterStart = pivot + 1, builder = start;
	while (Firststart <= pivot && LaterStart <= finish) {
		if (d[Firststart].age < d[LaterStart].age) {
			sort[builder].age = d[Firststart].age;
			strcpy(sort[builder++].name, d[Firststart++].name);
		}
		else if (d[Firststart].age > d[LaterStart].age) {
			sort[builder].age = d[LaterStart].age;
			strcpy(sort[builder++].name, d[LaterStart++].name);
		}
		// the case of same age
		else {
			if (d[Firststart].index < d[LaterStart].index) {
				sort[builder].age = d[Firststart].age;
				strcpy(sort[builder++].name, d[Firststart++].name);
			}
			else {
				sort[builder].age = d[LaterStart].age;
				strcpy(sort[builder++].name, d[LaterStart++].name);
			}
		}
	}
	while (Firststart <= pivot) {
		sort[builder].age = d[Firststart].age;
		strcpy(sort[builder++].name, d[Firststart++].name);
	}
	while (LaterStart <= finish) {
		sort[builder].age = d[LaterStart].age;
		strcpy(sort[builder++].name, d[LaterStart++].name);
	}
}