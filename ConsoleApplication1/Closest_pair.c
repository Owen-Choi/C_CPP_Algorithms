/*#include<stdio.h>
#include<stdlib.h>
#define min(a,b) (a > b ? b : a)
int point_num;

typedef struct {
	int x;
	int y;
}point;

point* S;
int counter = 0;
int compare(const void* a, const void* b);
void Solve(point* points);
void x_sort(point* points);
float Closest_pair(point* p, int startPos, int endPos);
int main() {

	scanf("%d", &point_num);
	point* points = (point*)malloc(sizeof(point) * point_num);
	for (int i = 0; i < point_num; i++) {
		scanf("%d %d", &points[i].x, &points[i].y);
	}
	//입력부 종료

	S = (point*)malloc(sizeof(point) * point_num);
	Solve(points);
	return 0;
}

void Solve(point* points) {
	//sort with x order
	x_sort(points);
	// call the function to get min distance value ::
	Closest_pair(points, 1, sizeof(points));
}

void x_sort(point* points) {
	qsort(points, point_num, sizeof(point), compare);
}

int compare(const void* a, const void* b) {
	if (((point*)a)->x < ((point*)b)->x)
		return -1;
	else
		return 1;
}

float Closest_pair(point* p, int startPos, int endPos) {
	if (endPos - 1 < 3) {
		// return Brute-Force Cpair? 
	}
	int q = (startPos + endPos) / 2;
	float dl = Closest_pair(p, startPos, q-1);
	float dr = Closest_pair(p, q, endPos);
	float d = min(dl, dr);
	for (int i = 1; i < endPos; i++) {
		// p[i].x가 사이에 존재한다면
		if (p[q].x - d <= p[i].x && p[i].x <= p[q].x + d) {
			// 전역변수에 할당.
			S[counter++] = p[i];
		}
	}
}*/

