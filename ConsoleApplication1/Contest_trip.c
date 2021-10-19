/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>

#define INF 10000;

char** cities;
int FindIndex(char* city, int cityNum);
void Dijkstra(int row, int col, int cityNum);
int* dist;
const int ;
typedef struct {
	int time;
	char cityName[20];
}Store;

typedef struct {
	int StartTime;
	int destTime;
	char Destination[20];
	char Start[20];
}List;

List** list;
int main() {

	int testcase, cityNum, ScheduleNum, Station, time, MinimumTime;
	char* tempCity;
	char From[20], To[20];
	scanf("%d", &testcase);
	for (int i = 0; i < testcase; i++) {
		scanf("%d", &cityNum);
		cities = (char**)calloc(cityNum, sizeof(char*));
		dist = (int*)calloc(cityNum, sizeof(int));
		list = (List**)calloc(cityNum, sizeof(List*));
		for (int i = 0; i < cityNum; i++) {
			cities[i] = (char*)calloc(20, sizeof(char));
			dist[i] = INT_MAX;
			list[i] = (List*)calloc(cityNum, sizeof(List));
			scanf("%s", cities[i]);
		}
		scanf("%d", &ScheduleNum);
		for (int i = 0; i < cityNum; i++) {
			for (int k = 0; k < cityNum; k++) {
				list[i][k].destTime = INF;
			}
		}
		int iter = 0, tempIndex;
		for (int i = 0; i < ScheduleNum; i++) {
			scanf("%d", &Station);
			Store* ts = (Store*)calloc(Station, sizeof(Store));
			for (int i = 0; i < Station; i++) {
				scanf("%d %s", &ts[i].time, &ts[i].cityName);
			}
			// now we have to link this value to list ::
			// first we have to initialize the arrival time value ::
			for (int k = 0; k < Station-1; k++) {
				tempIndex = FindIndex(ts[k].cityName, cityNum);
				list[tempIndex][iter].destTime = ts[k + 1].time;
				list[tempIndex][iter].StartTime = ts[k].time;
				strcpy(list[tempIndex][iter].Start, ts[k].cityName);
				strcpy(list[tempIndex][iter].Destination, ts[k + 1].cityName);
			}
			iter++;
			// 서로 같은 노선으로 연결된 도시들은 같은 col 상에 존재하게 된다.
			free(ts);
		}
		scanf("%d", &MinimumTime);
		scanf("%s", &From);
		scanf("%s", &To);
		printf("\n");

		for (int i = 0; i < cityNum; i++) {
			for (int k = 0; k < cityNum; k++) {
				printf("%d %s %d %s ", list[i][k].StartTime, list[i][k].Start, list[i][k].destTime,list[i][k].Destination);
			}
			printf("\n");
		}
	}
	return 0;
}

int FindIndex(char* city, int cityNum) {
	for (int i = 0; i < cityNum; i++) {
		if (strcmp(cities[i], city))
			return i;
	}
	printf("Cannot find any city with that name :: \n");
	printf("Please check the name of city");
	return -1;
}

void Dijkstra(int row, int col, int cityNum) {
	List temp;
	temp = list[row][col];
	int tempIndex, i = row;
		//Find temp.destination's DestTime, which is smallest ::
	while (i < cityNum) {
		for (int k = 0; k < cityNum; k++) {
			if (list[i][k].destTime == temp.destTime) {
				i++;
				temp = list[i][k];
				break;
			}
		}
	}
}*/