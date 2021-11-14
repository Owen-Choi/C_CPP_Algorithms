#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int target;
int setSize;
int* set;
int* buildSet;

bool promising(int i, int weight, int total);
void printSubset();
void sum_of_subsets(int index, int weight, int total);

int main() {
	printf("please enter the size of the size : ");
	scanf("%d", &setSize);
	set = (int*)malloc(sizeof(int) * setSize);
	buildSet = (int*)malloc(sizeof(int) * setSize);
	printf("////////////////////////////////////////////// \n");
	printf("Please enter the integers of the set : \n");
	for (int i = 0; i < setSize; i++) {
		scanf("%d", &set[i]);
		buildSet[i] = 0;
	}
	int sum = 0;
	printf("////////////////////////////////////////////// \n");
	printf("please enter the target sum : ");
	scanf("%d", &target);
	for (int i = 0; i < setSize; i++)
		sum += set[i];

	sum_of_subsets(-1, 0, sum);
}


bool promising(int index, int weight, int total) {
	if (weight + total >= target && (weight == target || weight + set[index + 1] <= target))
		return true;
	else
		return false;
}

void sum_of_subsets(int index, int weight, int total) {
	if (promising(index, weight, total)) {
		if (weight == target)
			printSubset();
		else {
			buildSet[index + 1] = set[index + 1];
			sum_of_subsets(index + 1, weight + set[index + 1], total - set[index + 1]);
			buildSet[index + 1] = 0;
			sum_of_subsets(index + 1, weight, total - set[index + 1]);
		}
	}
}

void printSubset() {
	for (int i = 0; i < setSize; i++) {
		if (buildSet[i] != 0) {
			printf("%d ", buildSet[i]);
		}
	}
	printf("\n");
}