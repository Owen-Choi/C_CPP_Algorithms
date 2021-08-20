#include<string.h>
#include<stdio.h>
using namespace std;
int main(void) {
	int testCase;
	scanf("%d", &testCase);
	char a[21];		//21글자의 크기를 갖는 char 배열 a의 시작 주소를 활용하면 이 배열을 string과 같이 쓸 수 있다.
	for (int j = 0; j < testCase; j++) {
		int dressNum, b[30] = {0}, result = 1;
		char c[30][21] = {};		//21글자의 크기를 갖는 char 배열을 30개 까지 가질 수 있는 2차원 배열이다.
		scanf("%d", &dressNum);
		for (int k = 0; k < dressNum; k++) {
			scanf("%s", a);
			scanf("%s", a);
			int iterator = 0;
			while (c[iterator][0] != 0) {
				if (strcmp(c[iterator], a) == 0)
					break;
				iterator++;
			}
			strcpy(c[iterator], a);
			b[iterator]++;
		}
		for (int i = 0; i < 30; i++) {
			if (b[i] != 0)
				result *= (b[i] + 1);
		}
		printf("%d \n", result - 1);
	}
}
