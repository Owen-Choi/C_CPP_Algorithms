/*#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

int dotNum;
float** dot;
float** dist;
int* parent;
int list_pointer = 0;
float Result = 0.0;
float getDist(float X1, float X2, float Y1, float Y2);
bool isEmpty();
void add(int Start, int End, float Weight);
int getEdge();
void UnionParent(int firstIndex, int SecondIndex);
int getParent(int Index);
bool cycleCheck(int firstIndex, int SecondIndex);
typedef struct {
	int StartPoint;
	int EndPoint;
	float Weight;
}Node;
Node* node;

int compare(const void* a, const void* b) {
	if (((Node*)a)->Weight < ((Node*)b)->Weight)
		return 1;
	else
		return -1;
}

int main() {
	FILE* fp;
	fp = fopen("C:\\Users\\oldst\\Desktop\\201835539 √÷√∂øı\\Input3.txt", "r");
	if (fp == NULL) {
		printf("cannot find any files \n");
		exit(1);
	}
	fscanf(fp, "%d\n", &dotNum);
	dot = (float**)calloc(dotNum, sizeof(float*));
	dist = (float**)calloc(dotNum, sizeof(float*));
	node = (Node*)calloc(getEdge() + 1, sizeof(Node));
	parent = (int*)malloc(sizeof(int) * dotNum + 1);
	for (int i = 0; i < dotNum; i++) {
		dot[i] = (float*)calloc(2, sizeof(i));
		dist[i] = (float*)calloc(dotNum, sizeof(i));
		parent[i + 1] = i + 1;
		fscanf(fp, "%f %f\n", &dot[i][0], &dot[i][1]);
	}
	// Input ends ::
	for (int i = 0; i < dotNum; i++) {
		for (int k = i + 1; k < dotNum; k++) {
			dist[i][k] = getDist(dot[i][0], dot[k][0], dot[i][1], dot[k][1]);
		}
	}
	// storing distance value ends ::
	for (int i = 0; i < dotNum; i++) {
		for (int k = i+1; k < dotNum; k++) {
			add(i + 1, k + 1, dist[i][k]);
		}
	}
	int EdgeNum = getEdge();
	int tempS, tempE;
	float tempWeight;
	qsort(node, EdgeNum, sizeof(node[0]), compare);

	list_pointer--;
	while (!isEmpty()) {
		tempS = node[list_pointer].StartPoint;
		tempE = node[list_pointer].EndPoint;
		tempWeight = node[list_pointer--].Weight;
		if (!cycleCheck(tempS, tempE)) {
			Result += tempWeight;
			UnionParent(tempS, tempE);
		}
	}
	printf("%0.2f \n", Result);
	printf("\n");
	return 0;
}

float getDist(float X1, float X2, float Y1, float Y2) {
	return sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
}
int getEdge() {
	int EdgeNum = 0;
	for (int i = dotNum - 1; i > 0; i--) {
		EdgeNum += i;
	}
	return EdgeNum;
}

bool isEmpty() {
	return list_pointer == 0 ? true : false;
}

void add(int Start, int End, float Weight) {
	node[list_pointer].StartPoint = Start;
	node[list_pointer].EndPoint = End;
	node[list_pointer++].Weight = Weight;
}

int getParent(int Index) {
	if (parent[Index] == Index)
		return Index;
	parent[Index] = getParent(parent[Index]);
	return parent[Index];
}

void UnionParent(int First, int Second) {
	First = getParent(First);
	Second = getParent(Second);
	if (First < Second)
		parent[Second] = First;
	else
		parent[First] = Second;
}

bool cycleCheck(int First, int Second) {
	return getParent(First) == getParent(Second);
}*/