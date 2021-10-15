/*#include<stdio.h>
#include<stdlib.h>

#define INF 0x5F5E100;
int centerNum, interNum;
int* centers;
int** dist;

void Solve();
//void Convert();
void Find();

int main() {
	scanf("%d %d", &centerNum, &interNum);
	centers = (int*)malloc(sizeof(int) * centerNum);
	for (int i = 0; i < centerNum; i++) {
		scanf("%d", &centers[i]);
	}
	dist = (int**)malloc(sizeof(int*) * interNum);
	for (int i = 0; i < interNum; i++)
		dist[i] = (int*)malloc(sizeof(int) * interNum);

	for (int i = 0; i < interNum; i++) {
		for (int k = 0; k < interNum; k++) {
			dist[i][k] = INF;
		}
	}

	int tempS, tempF, tempW;
	for (int i = 0; i < interNum; i++) {
		scanf("%d %d %d", &tempS, &tempF, &tempW);
		dist[tempS - 1][tempF - 1] = tempW;
		dist[tempF-1][tempS-1] = tempW;
	}
	Solve();
	return 0;
}

void Solve() {
	for (int pivot = 0; pivot < interNum; pivot++) {
		for (int i = 0; i < interNum; i++) {
			for (int k = 0; k < interNum; k++) {
				if (dist[i][k] > dist[i][pivot] + dist[pivot][k])
					dist[i][k] = dist[i][pivot] + dist[pivot][k];
			}
		}
	}
	//Convert();

	for (int i = 0; i < interNum; i++) {
		for (int k = 0; k < interNum; k++) {
			if (dist[i][k] == 0x5F5E100)
				printf("INF ");
			else
				printf("%d ", dist[i][k]);
		}
		printf("\n");
	}
	Find();
}*/

/*void Convert() {
	int tempValue;
	for (int i = 0; i < interNum; i++) {
		for (int k = 0; k < interNum; k++) {
			tempValue = dist[i][k];
			if (MAX - tempValue < tempValue)
				dist[i][k] = MAX - tempValue;
		}
	}
}*/

/*
void Find() {
	int max = -1;
	int result = 0;
	for (int i = 0; i < centerNum; i++) {
		for (int k = 0; k < interNum; k++) {
			if (dist[k][centers[i] - 1] > max) {
				max = dist[k][centers[i] - 1];
				result = k + 1;
			}
		}
	}
	printf("%d", result);
}*/