/*#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int TestCase, Vertex, Edge;
int* parent;
int* priority;
// function for sorting. like compartor in java ::
// quick sort를 위한 함수입니다. 자바에서의 comparator 인터페이스처럼 정렬 기준을 사용자가 정의할 수 있는 함수라고 생각하시면 되겠습니다.
// 편의상 stdlib 헤더를 추가하고 qsort 함수를 사용하였지만, 원래는 저희가 직접 정렬을 구현해야 합니다.
int compare(const void* a, const void* b);
// To Know the Parent index of parameter value ::
// 싸이클을 체크하기 위해선 별도로 선언한 부모배열의 값이 필요합니다. 그 부모 배열의 값을 받아오기 위한 함수입니다.
int GetParent(int Index);
// To Make the parent value same ::
// 서로 연결되어있는 노드는 같은 부모를 가져야 하고, 그럼으로써 사이클을 방지할 수 있습니다. 그러기 위해서 부모를 합쳐주는 작업이 필요합니다.
void MergeParent(int FirstIndex, int SecondIndex);
// For this function, that returning boolean value, I added stdbool header, but it can be replaced with return 1, 0 ::
// 부모배열의 값을 바탕으로 사이클이 일어나는지 일어나지 않는지 확인하는 함수입니다.
// 프림과 마찬가지로 bool 값을 바로 사용하기 위해 stdbool 헤더를 추가했습니다. 그러지 않고 int 타입으로 선언한 뒤 true : 1 false : 0으로 사용해도 됩니다.
bool CycleCheck(int FirstIndex, int SecondIndex);

typedef struct {
	int Start;
	int Dest;
	int Distance;
}Node;
//크루스칼 알고리즘을 통해서 최소비용경로를 찾고 그 과정을 출력하는 함수입니다.
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
		// 여기까지 정점과 간선, 테스트 케이스의 수를 입력받았습니다.
		// 이 값들을 바탕으로 구조체의 수, 부모 배열의 크기를 동적할당해줍니다. 
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
			// 여기까지 정점과 간선을 입력받았습니다.
		}
		Solve(node);
		
	}
	return 0;
}

int compare(const void* a, const void* b) {
	//qsort 함수를 사용하기 위한 기준이 됩니다. 구조체의 Distance 값을 기준으로 오름차순으로 정렬합니다.
	// 크루스칼은 간선 위주의 알고리즘이기 때문에, 간선을 먼저 오름차순으로 정렬 후 그 값을 기준으로 노드들을 연결합니다.
	// 따라서 이 과정이 크루스칼의 핵심이라고 할 수 있고, 크루스칼 알고리즘의 시간복잡도는 정렬의 영향을 가장 많이 받습니다.
	return ((Node*)a)->Distance - ((Node*)b)->Distance;
}

void Solve(Node* node) {
	// first, Sort Struct by ascending order of distance ::
	// 간선의 크기를 오름차순 기준으로 정렬
	qsort(node, Edge, sizeof(node[0]), compare);

	int Result = 0;
	for (int i = 0; i < Edge; i++) {
		// 간선을 기준으로 오름차순으로 정렬하였기 때문에, 단순히 for문만 돌려주며 앞의 노드들의 간선을 더하다보면 최소로 트리를 구성할 수 있습니다.
		// 따라서 우리는 반복문을 통해 값을 더해주되, 사이클이 생기는 경우만 피하고 더해주면 MST를 구성해줄 수 있습니다.
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
	// 이 부분이 이해가 잘 안가실텐데, 재귀를 통해서 계속해서 타고 들어가 결국 한 부모를 가리키게 만듭니다.
	// 그리고 이 '한 부모'는 MergeParent 함수에서 보실 수 있지만, 두 노드 중 작은 노드가 되게 됩니다.
	// 즉 작은 노드 3, 노드 5, 노드 7, 노드 1 이렇게 연결되어있다면, 이 노드들의 부모값은 모두 1이 되게 되고,
	// 아래의 코드는 노드 3, 노드 5, 노드 7이 재귀를 통해 타고 타고 들어가 결국 노드 1에서 1을 return하게 해주는 역할을 합니다.
	parent[Index] = GetParent(parent[Index]);
	return parent[Index];
}
bool CycleCheck(int FIrstIndex, int SecondIndex) {
	// If parent value is same, return true, and that means there will be cycles ::
	// 가리키는 부모가 같다면 노드 둘은 연결이 되어있고, 사이클이 생긴다는 것을 의미하게 됩니다. 
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