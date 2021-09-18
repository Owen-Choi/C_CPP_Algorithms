#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int Vertex, Edge;
int* parent;
// function for sorting. like compartor in java ::
int compare(const void* a, const void* b);
// To Know the Parent index of parameter value ::
int GetParent(int Index);
// To Make the parent value same ::
void MergeParent(int FirstIndex, int SecondIndex);
// For this function, that returning boolean value, I added stdbool header, but it can be replaced with return 1, 0 ::
bool CycleCheck(int FirstIndex, int SecondIndex);
typedef struct {
	int Start;
	int Dest;
	int Distance;
}Node;
void Solve(Node* node);
int main() {
	printf("Please Enter the Number of Vertex : ");
	scanf("%d", &Vertex);
	printf("Please Enter the Number of Edge : ");
	scanf("%d", &Edge);
	// First get the value of Vertex and Edge :: 
	Node* node = (Node*)malloc(sizeof(Node) * Edge);
	parent = (int*)malloc(sizeof(int) * Vertex + 1);
	// Initializing parent array ::
	for (int i = 0; i <= Vertex; i++) 
		parent[i] = i;
	printf("\n Please Enter the Value with Format :: StartVertex : DestinationVertex : Distance \n");
	for (int i = 0; i < Edge; i++) {
		scanf("%d %d %d", &node[i].Start, &node[i].Dest, &node[i].Distance);
		// Input Ends ::
	}
	Solve(node);
	return 0;
}

int compare(const void* a, const void* b) {
	return ((Node*)a)->Distance - ((Node*)b)->Distance;
}

void Solve(Node* node) {
	// first, Sort Struct by ascending order of distance ::
	qsort(node, Edge, sizeof(node[0]), compare);

	int Result = 0;
	for (int i = 1; i <= Vertex; i++) {
		if (!CycleCheck(node[i - 1].Start, node[i - 1].Dest)) {
			Result += node[i-1].Distance;
			MergeParent(node[i - 1].Start, node[i - 1].Dest);
		}
	}
	printf("\n%d is the Shortest distance \n", Result);
}
int GetParent(int Index) {
	if (parent[Index] == Index)
		return Index;
	return parent[Index] = GetParent(parent[Index]);
}
bool CycleCheck(int FIrstIndex, int SecondIndex) {
	// If parent value is same, return true, and that means there will be cycles ::
	return GetParent(FIrstIndex) == GetParent(SecondIndex);
}
void MergeParent(int FirstIndex, int SecondIndex) {
	// Make parent same to Prevent Cycle ::
	int FirstParent = GetParent(FirstIndex);
	int SecondParent = GetParent(SecondIndex);
	if (FirstParent < SecondParent)
		parent[SecondIndex] = FirstParent;
	else
		parent[FirstIndex] = SecondParent;
}