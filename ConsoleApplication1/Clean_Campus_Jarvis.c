#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

int testCase;
int Fresh_num;

typedef struct{
	float x, y;
	bool visited;
}Fresh;

Fresh* freshes;

// to determine the direction : CW or CCW or linear
int Find_Direction(Fresh a, Fresh b, Fresh c);

// to find the convex hull :: 
// first we will calculate an entire convex hull
// and then we will find the value which is the result of the case we will start with the point(0,0)
void Convex_hull();

// to get the result that is the total length of silk
float calc_value(Fresh* buffer, int counter, Fresh init);

// to get the distance between two fresh mans
float getDist(Fresh tempFresh, Fresh tempFresh2);

// to know the Freshman who satisfy certain conditions
// that is, not on the line(x = 0 || y = 0) and not on the same line
bool typeCheck(Fresh pivot, Fresh fresh);

int main() {

	scanf("%d", &testCase);
	for (int i = 0; i < testCase; i++) {
		scanf("%d", &Fresh_num);
		freshes = (Fresh*)malloc(sizeof(Fresh) * Fresh_num + 1);
		for (int k = 0; k <= Fresh_num; k++) {
			if (k == 0) {
				freshes[0].x = 0.0;
				freshes[0].y = 0.0;
				continue;
			}
			scanf("%f %f", &freshes[k].y, &freshes[k].x);
		}
		// input part end :: 
		Convex_hull();
	}
	return 0;
}

int Find_Direction(Fresh a, Fresh b, Fresh c) {
	float value = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
	// value == 0.0 means the three point is on the same line.
	if (value == 0.0)
		return value;
	// 1 : clock wise direction
	// 2 : couter-clock wise direction
	return (value > 0) ? 1 : 2;
}

void Convex_hull() {
	// to store points(freshes) that is tied
	Fresh* buffer;
	buffer = (Fresh*)malloc(sizeof(Fresh) * Fresh_num + 1);
	int left = 0;
	for (int i = 0; i <= Fresh_num; i++) {
		if (freshes[i].x < freshes[left].x)
			left = i;
	}
	int index = left, q, counter = 0;
	do {
		buffer[counter++] = freshes[index];
		q = (index + 1) % Fresh_num;
		for (int i = 0; i <= Fresh_num; i++) {
			if (Find_Direction(freshes[index], freshes[i], freshes[q]) == 2) {
				q = i;
			}
		}
		index = q;
		freshes[index].visited = true;
	} while (index != left);

	printf("%.2f", calc_value(buffer, counter, freshes[0]));
}

float calc_value(Fresh* buffer, int counter, Fresh init) {

	Fresh min1, min2;
	float min = 1000000, tempDist;
	int tempIndex;
	for (int i = 1; i < counter; i++) {
		tempDist = getDist(buffer[i], init);
		if (tempDist < min && buffer[i].visited) {
			min = tempDist;
			min1 = buffer[i];
			tempIndex = i;
		}
	}
	min = 1000000;
	for (int i = 1; i < counter; i++) {
		if (i == tempIndex)
			continue;
		tempDist = getDist(buffer[i], init);
		if (tempDist < min && buffer[i].visited && typeCheck(min1, buffer[i])) {
			min = tempDist;
			min2 = buffer[i];
		}
	}
	Fresh prior, temp, start;
	float result = 0.0;
	int metaCounter = 0;
	for (int i = 0; i < counter; i++) {
		if (i == 0) {
			prior = start = buffer[metaCounter++];
		}
		else {
			temp = buffer[metaCounter++];
			result += getDist(prior, temp);
			prior = temp;
		}
	}
	// connect last fresh and the first fresh(not 0,0)
	// and then we have to tie silk, add additional 2 m
	result += getDist(temp, start) + 2;

	// delete connection between min1 and min2
	result -= getDist(min1, min2);
	// and add the distance between (0,0) and min1, and (0,0) and min2
	result += getDist(min1, init) + getDist(min2, init);
	return result;
}

float getDist(Fresh tempFresh, Fresh tempFresh2) {
	return sqrt(pow(tempFresh.x - tempFresh2.x, 2) + pow(tempFresh.y - tempFresh2.y, 2));
}

bool typeCheck(Fresh pivot, Fresh fresh) {
	// if the two freshes stand in the same x - axis or y - axis(but not for both) line, 
	// then this freshe can't be the min2
	if (pivot.x >= 0 && fresh.x <= 0 && pivot.y == 0 && fresh.y == 0)
		return false;
	else if (pivot.x <= 0 && fresh.x >= 0 && pivot.y == 0 && fresh.y == 0)
		return false;
	else if (pivot.y >= 0 && fresh.y <= 0 && pivot.x == 0 && fresh.x == 0)
		return false;
	else if (pivot.y <= 0 && fresh.y >= 0 && pivot.x == 0 && fresh.x == 0)
		return false;
	// if freshes not satisfy all of the above, then this fresh can be the min2
	else
		return true;
}