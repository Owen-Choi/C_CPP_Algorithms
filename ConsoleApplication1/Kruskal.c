/*#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int TestCase, Vertex, Edge;
int* parent;
int* priority;
// function for sorting. like compartor in java ::
// quick sort�� ���� �Լ��Դϴ�. �ڹٿ����� comparator �������̽�ó�� ���� ������ ����ڰ� ������ �� �ִ� �Լ���� �����Ͻø� �ǰڽ��ϴ�.
// ���ǻ� stdlib ����� �߰��ϰ� qsort �Լ��� ����Ͽ�����, ������ ���� ���� ������ �����ؾ� �մϴ�.
int compare(const void* a, const void* b);
// To Know the Parent index of parameter value ::
// ����Ŭ�� üũ�ϱ� ���ؼ� ������ ������ �θ�迭�� ���� �ʿ��մϴ�. �� �θ� �迭�� ���� �޾ƿ��� ���� �Լ��Դϴ�.
int GetParent(int Index);
// To Make the parent value same ::
// ���� ����Ǿ��ִ� ���� ���� �θ� ������ �ϰ�, �׷����ν� ����Ŭ�� ������ �� �ֽ��ϴ�. �׷��� ���ؼ� �θ� �����ִ� �۾��� �ʿ��մϴ�.
void MergeParent(int FirstIndex, int SecondIndex);
// For this function, that returning boolean value, I added stdbool header, but it can be replaced with return 1, 0 ::
// �θ�迭�� ���� �������� ����Ŭ�� �Ͼ���� �Ͼ�� �ʴ��� Ȯ���ϴ� �Լ��Դϴ�.
// ������ ���������� bool ���� �ٷ� ����ϱ� ���� stdbool ����� �߰��߽��ϴ�. �׷��� �ʰ� int Ÿ������ ������ �� true : 1 false : 0���� ����ص� �˴ϴ�.
bool CycleCheck(int FirstIndex, int SecondIndex);

typedef struct {
	int Start;
	int Dest;
	int Distance;
}Node;
//ũ�罺Į �˰����� ���ؼ� �ּҺ���θ� ã�� �� ������ ����ϴ� �Լ��Դϴ�.
void Solve(Node* node);
int main() {
	printf("Please Enter TestCase : ");
	scanf("%d", &TestCase);
	for (int i = 0; i < TestCase; i++) {
		printf("Please Enter the Number of Vertex : ");
		scanf("%d", &Vertex);
		printf("Please Enter the Number of Edge : ");
		scanf("%d", &Edge);
		// First get the value of Vertex and Edge :: 
		// ������� ������ ����, �׽�Ʈ ���̽��� ���� �Է¹޾ҽ��ϴ�.
		// �� ������ �������� ����ü�� ��, �θ� �迭�� ũ�⸦ �����Ҵ����ݴϴ�. 
		Node* node = (Node*)malloc(sizeof(Node) * Edge);
		parent = (int*)malloc(sizeof(int) * Vertex + 1);
		priority = (int*)malloc(sizeof(int) * Vertex);
		// Initializing parent array ::
		for (int i = 0; i <= Vertex; i++) {
			parent[i] = i;
			priority[i] = 0;
		}
		printf("\n Please Enter the Value with Format :: StartVertex : DestinationVertex : Distance \n");
		for (int i = 0; i < Edge; i++) {
			scanf("%d %d %d", &node[i].Start, &node[i].Dest, &node[i].Distance);
			// Input Ends ::
			// ������� ������ ������ �Է¹޾ҽ��ϴ�.
		}
		Solve(node);
		
	}
	return 0;
}

int compare(const void* a, const void* b) {
	//qsort �Լ��� ����ϱ� ���� ������ �˴ϴ�. ����ü�� Distance ���� �������� ������������ �����մϴ�.
	// ũ�罺Į�� ���� ������ �˰����̱� ������, ������ ���� ������������ ���� �� �� ���� �������� ������ �����մϴ�.
	// ���� �� ������ ũ�罺Į�� �ٽ��̶�� �� �� �ְ�, ũ�罺Į �˰����� �ð����⵵�� ������ ������ ���� ���� �޽��ϴ�.
	return ((Node*)a)->Distance - ((Node*)b)->Distance;
}

void Solve(Node* node) {
	// first, Sort Struct by ascending order of distance ::
	// ������ ũ�⸦ �������� �������� ����
	qsort(node, Edge, sizeof(node[0]), compare);

	int Result = 0;
	for (int i = 0; i < Edge; i++) {
		// ������ �������� ������������ �����Ͽ��� ������, �ܼ��� for���� �����ָ� ���� ������ ������ ���ϴٺ��� �ּҷ� Ʈ���� ������ �� �ֽ��ϴ�.
		// ���� �츮�� �ݺ����� ���� ���� �����ֵ�, ����Ŭ�� ����� ��츸 ���ϰ� �����ָ� MST�� �������� �� �ֽ��ϴ�.
		if (!CycleCheck(node[i].Start, node[i].Dest)) {
			Result += node[i].Distance;
			printf("(%c %c), total weight : %d \n", node[i].Start + 96, node[i].Dest + 96, Result);
			MergeParent(node[i].Start, node[i].Dest);
		}
	}
	/*printf("\n");
	for (int i = 0; i <= Edge; i++) {
		printf("%d %d %d \n", node[i].Start, node[i].Dest, node[i].Distance);
	}
	printf("\n%d is the Shortest distance \n", Result);*/
/*
}
int GetParent(int Index) {
	if (parent[Index] == Index)
		return Index;
	// �� �κ��� ���ذ� �� �Ȱ����ٵ�, ��͸� ���ؼ� ����ؼ� Ÿ�� �� �ᱹ �� �θ� ����Ű�� ����ϴ�.
	// �׸��� �� '�� �θ�'�� MergeParent �Լ����� ���� �� ������, �� ��� �� ���� ��尡 �ǰ� �˴ϴ�.
	// �� ���� ��� 3, ��� 5, ��� 7, ��� 1 �̷��� ����Ǿ��ִٸ�, �� ������ �θ��� ��� 1�� �ǰ� �ǰ�,
	// �Ʒ��� �ڵ�� ��� 3, ��� 5, ��� 7�� ��͸� ���� Ÿ�� Ÿ�� �� �ᱹ ��� 1���� 1�� return�ϰ� ���ִ� ������ �մϴ�.
	parent[Index] = GetParent(parent[Index]);
	return parent[Index];
}
bool CycleCheck(int FIrstIndex, int SecondIndex) {
	// If parent value is same, return true, and that means there will be cycles ::
	// ����Ű�� �θ� ���ٸ� ��� ���� ������ �Ǿ��ְ�, ����Ŭ�� ����ٴ� ���� �ǹ��ϰ� �˴ϴ�. 
	return GetParent(FIrstIndex) == GetParent(SecondIndex);
}
void MergeParent(int FirstIndex, int SecondIndex) {
	// Make parent same to Prevent Cycle ::
	int FirstParent = GetParent(FirstIndex);
	int SecondParent = GetParent(SecondIndex);
	if (FirstParent < SecondParent)
		parent[SecondParent] = FirstParent;
	else
		parent[FirstParent] = SecondParent;
}*/