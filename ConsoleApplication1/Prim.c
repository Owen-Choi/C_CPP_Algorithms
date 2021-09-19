#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int testCase, Vertex, Edge;
int* dist;
int* primTree;
int** graph;
bool* flag;
const int INF = 0x5F5E100;
// �����ִ� ���� �߿� ���� ����� ������ �ε����� ��ȯ�մϴ�.
// �̹� �湮�� ��� �߿��� ���� ����� ������ ã���� �ȵǹǷ� boolean Ÿ���� ���� �迭�� �����մϴ�.
int FindMin(int FirstValue, int SecondValue);
// Prim �˰����� ���ؼ� �ִܰ�θ� ã���� ������ ������� �Լ��Դϴ�.
void Solve(int** graph);

int main() {
	printf("Please Enter TestCase : ");
	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		printf("Please Enter the number of Vertex : ");
		scanf("%d", &Vertex);
		printf("Please Enter the number of Edge : ");
		scanf("%d", &Edge);
			// ��������� �׽�Ʈ���̽�, ����, ������ ������ �Է¹޽��ϴ�.
			// ���� �Է¹��� ������ ����,������ ������ �������� �����Ҵ��� ���� �迭�� �������ݴϴ�.
			// bool Ÿ���� ������ �ٷ� ����ϱ� ���� stdbool ����� �߰�������ϴ�. �׷��� ���� ��� int�� �����ϰ� 
			// true : 1 false : 0���� ����ϸ� �˴ϴ�.
		flag = (bool*)malloc(sizeof(bool) * Vertex);
		primTree = (int*)malloc(sizeof(int) * Vertex);
		dist = (int*)malloc(sizeof(int) * Vertex);
			//�ε����� ���� �ٸ� ��尣�� �Ÿ��� ��Ÿ���� ���� 2���� �迭 graph�� �����մϴ�.
		graph = (int**)malloc(sizeof(int*) * Vertex);
		for (int i = 0; i < Vertex; i++)
			graph[i] = (int*)malloc(sizeof(int) * Vertex);
			//graph�� ��� value�� INF�� �ʱ�ȭ�ϰڽ��ϴ�. INF�� ���� ������ �ִ밪���� ������ overflow �߻��� �����ϱ� ���� 1������ �����Ͽ����ϴ�.
		for (int i = 0; i < Vertex; i++) {
			for (int k = 0; k < Vertex; k++) {
				graph[i][k] = INF;
			}
		}
			// ���⼭���ʹ� �� ���� ������ �Ÿ��� �Է¹޽��ϴ�.
		printf("\n Please Enter the Value with Format :: StartVertex : DestinationVertex : Distance \n");
		int tempStart, tempDest, tempDist;
		for (int i = 0; i < Edge; i++) {
			scanf("%d %d %d", &tempStart, &tempDest, &tempDist);
			// ������ ������ �ʱ� ������ �ֹ����� ����Ǿ�� �մϴ�. �߿��� �κ�.
			graph[tempStart - 1][tempDest - 1] = tempDist;
			graph[tempDest - 1][tempStart - 1] = tempDist;
		}
		Solve(graph);
	}
}
void Solve(int** graph) {
		// ������ �Ÿ����� ��� INF��, �湮 �迭�� ��� false(�湮���� ����)�� �ʱ�ȭ���ݴϴ�.
	for (int i = 0; i < Vertex; i++) {
		dist[i] = INF;
		flag[i] = false;
	}
		//� ������ �����ϴ� ���������, ���� ù��° ���, �� 0��° �ε������� �����ϰڽ��ϴ�.
	dist[0] = 0;
	primTree[0] = -1;
	int TempMinIndex;
	for (int i = 0; i < Vertex - 1; i++) {
		//�ּҰ��� ã���ϴ�. ���� ����Ž������ �ּҰ��� ã����, ����Ž���� brute-force ������� ���� ��ȿ�����Դϴ�.
		//�ּҰ��� ã�� �˰������δ� �� ���� ���� �� �ֽ��ϴ�. �� �˰����� ���� �˰����� ���ɿ� ���� ������ �شٰ� �ϴ� �����Ͻñ� �ٶ��ϴ�. 
		TempMinIndex = FindMin(dist, flag);
		//�ּҰ��� ã���� ��� �� �ּҰ��� ��带 �湮�ߴٴ� �ǹ̷� flag �迭�� true�� �ٲ��ݴϴ�.
		flag[TempMinIndex] = true;
		for (int k = 0; k < Vertex; k++) {
			//�ּҰ��� ������ ã�����Ƿ� �� ������ ����������鼭 �Ÿ��� ���� ���� �ֺ��� ������ ã���� ���ÿ� �Ÿ����� ������Ʈ ���ݴϴ�.
			if (graph[TempMinIndex][k]!= INF && !flag[k] && graph[TempMinIndex][k] < dist[k]) {
				primTree[k] = TempMinIndex;
				dist[k] = graph[TempMinIndex][k];
			}
		}
	}
		//������� prim�˰������� primTree �迭�� �ϼ��߽��ϴ�. ���� primTree�迭�� �ϳ��� ����ϸ鼭 ����ġ�� �����ָ� �˴ϴ�.
	int sum = 0;
	for (int i = 1; i < Vertex; i++) {
		sum += graph[i][primTree[i]];
		printf("(%d %d), total weight : %d\n", primTree[i] + 1, i + 1, sum);
	}
	printf("\n%d is the Shortest distance \n", sum);
}

int FindMin(int* dist, bool* flag) {
		//Vertex�� �� ��ŭ for���� ���� ����Ž���ϸ� �ּҰ��� ã��. �������� �߿��� �κ��� �� �ּҰ��� ã�� �κ��Դϴ�.
	int Min = INF, minIndex = 0;
	for (int i = 0; i < Vertex; i++) {
		if (flag[i] == false && dist[i] < Min) {
			Min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}