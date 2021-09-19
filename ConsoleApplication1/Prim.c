#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int testCase, Vertex, Edge;
int* dist;
int* primTree;
int** graph;
bool* flag;
const int INF = 0x5F5E100;
// 남아있는 정점 중에 가장 가까운 정점의 인덱스를 반환합니다.
// 이미 방문한 노드 중에서 가장 가까운 정점을 찾으면 안되므로 boolean 타입의 정적 배열을 선언합니다.
int FindMin(int FirstValue, int SecondValue);
// Prim 알고리즘을 통해서 최단경로를 찾으며 과정을 출력해줄 함수입니다.
void Solve(int** graph);

int main() {
	printf("Please Enter TestCase : ");
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		printf("Please Enter the number of Vertex : ");
		scanf("%d", &Vertex);
		printf("Please Enter the number of Edge : ");
		scanf("%d", &Edge);
			// 여기까지는 테스트케이스, 정점, 간선의 개수를 입력받습니다.
			// 이제 입력받은 정점의 개수,간선의 개수를 바탕으로 동적할당을 통해 배열을 선언해줍니다.
			// bool 타입의 변수를 바로 사용하기 위해 stdbool 헤더를 추가해줬습니다. 그렇지 않을 경우 int로 선언하고 
			// true : 1 false : 0으로 사용하면 됩니다.
		flag = (bool*)malloc(sizeof(bool) * Vertex);
		primTree = (int*)malloc(sizeof(int) * Vertex);
		dist = (int*)malloc(sizeof(int) * Vertex);
			//인덱스의 노드와 다른 노드간의 거리를 나타내기 위한 2차원 배열 graph를 선언합니다.
		graph = (int**)malloc(sizeof(int*) * Vertex);
		for (int i = 0; i < Vertex; i++)
			graph[i] = (int*)malloc(sizeof(int) * Vertex);
			//graph의 모든 value를 INF로 초기화하겠습니다. INF는 보통 정수의 최대값으로 넣지만 overflow 발생을 방지하기 위해 1억으로 설정하였습니다.
		for (int i = 0; i < Vertex; i++) {
			for (int k = 0; k < Vertex; k++) {
				graph[i][k] = INF;
			}
		}
			// 여기서부터는 각 정점 사이의 거리를 입력받습니다.
		printf("\n Please Enter the Value with Format :: StartVertex : DestinationVertex : Distance \n");
		int tempStart, tempDest, tempDist;
		for (int i = 0; i < Edge; i++) {
			scanf("%d %d %d", &tempStart, &tempDest, &tempDist);
			// 방향을 가지지 않기 때문에 쌍방으로 연결되어야 합니다. 중요한 부분.
			graph[tempStart - 1][tempDest - 1] = tempDist;
			graph[tempDest - 1][tempStart - 1] = tempDist;
		}
		Solve(graph);
	}
}
void Solve(int** graph) {
		// 최초의 거리값을 모두 INF로, 방문 배열은 모두 false(방문하지 않음)로 초기화해줍니다.
	for (int i = 0; i < Vertex; i++) {
		dist[i] = INF;
		flag[i] = false;
	}
		//어떤 노드부터 시작하던 상관없지만, 저는 첫번째 노드, 즉 0번째 인덱스부터 시작하겠습니다.
	dist[0] = 0;
	primTree[0] = -1;
	int TempMinIndex;
	for (int i = 0; i < Vertex - 1; i++) {
		//최소값을 찾습니다. 저는 선형탐색으로 최소값을 찾지만, 선형탐색은 brute-force 방식으로 가장 비효율적입니다.
		//최소값을 찾는 알고리즘으로는 힙 등이 사용될 수 있습니다. 이 알고리즘이 프림 알고리즘의 성능에 많은 영향을 준다고 하니 참고하시기 바랍니다. 
		TempMinIndex = FindMin(dist, flag);
		//최소값을 찾았을 경우 이 최소값의 노드를 방문했다는 의미로 flag 배열을 true로 바꿔줍니다.
		flag[TempMinIndex] = true;
		for (int k = 0; k < Vertex; k++) {
			//최소값의 정점을 찾았으므로 이 정점과 연결돼있으면서 거리가 가장 작은 주변의 정점을 찾음과 동시에 거리값을 업데이트 해줍니다.
			if (graph[TempMinIndex][k]!= INF && !flag[k] && graph[TempMinIndex][k] < dist[k]) {
				primTree[k] = TempMinIndex;
				dist[k] = graph[TempMinIndex][k];
			}
		}
	}
		//여기까지 prim알고리즘으로 primTree 배열을 완성했습니다. 이제 primTree배열을 하나씩 출력하면서 가중치를 더해주면 됩니다.
	int sum = 0;
	for (int i = 1; i < Vertex; i++) {
		sum += graph[i][primTree[i]];
		printf("(%d %d), total weight : %d\n", primTree[i] + 1, i + 1, sum);
	}
	printf("\n%d is the Shortest distance \n", sum);
}

int FindMin(int* dist, bool* flag) {
		//Vertex의 수 만큼 for문을 통해 선형탐색하며 최소값을 찾음. 프림에서 중요한 부분은 이 최소값을 찾는 부분입니다.
	int Min = INF, minIndex = 0;
	for (int i = 0; i < Vertex; i++) {
		if (flag[i] == false && dist[i] < Min) {
			Min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}