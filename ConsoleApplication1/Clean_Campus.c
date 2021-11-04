#include<stdio.h>
#include<stdlib.h>

int tc;
int fresh_num;

typedef struct {
	float x;
	float y;
}fresh_cord;

fresh_cord* fresh;
int compare(const void* a, const void* b);
void Solve();
int main() {

	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		// blank
		scanf("%d", &fresh_num);
		fresh = (fresh_cord*)malloc(sizeof(fresh_cord) * fresh_num);
		for (int k = 0; k < fresh_num; k++) {
			scanf("%f %f", &fresh[k].x, &fresh[k].y);
		}
	}
	//	sorting
	qsort(fresh, fresh_num, sizeof(fresh_cord), compare);
	for (int k = 0; k < fresh_num; k++) {
		printf("%f %f \n", fresh[k].x, fresh[k].y);
	}

	return 0;
}

int compare(const void* a, const void* b) {
	if (((fresh_cord*)a)->x < ((fresh_cord*)b)->x)
		return -1;
	else
		return 1;
}

void Solve() {

}