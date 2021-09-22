/*#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	int x;
	int y;
}coordinate;

int compare(const void* a, const void* b) {
	coordinate* first = (coordinate *)a;
	coordinate* second = (coordinate*)b;
	if (first->x < second->x)
		return -1;
	else if (first->x > second->x)
		return 1;
	else {
		if (first->y < second->y)
			return -1;
		else
			return 1;
	}
	return 0;
}

int main() {
	int PointNum;
	coordinate* list;
	scanf("%d", &PointNum);
	list = malloc(sizeof(coordinate) * PointNum);
	for (int i = 0; i < PointNum; i++) {
		scanf("%d %d", &list[i].x, &list[i].y);
	}
	qsort(list, PointNum,sizeof(list[0]), compare);
	for (int i = 0; i < PointNum; i++) {
		printf("%d %d\n", list[i].x, list[i].y);
	}
}
*/