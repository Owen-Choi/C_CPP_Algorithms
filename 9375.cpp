#include<string.h>
#include<stdio.h>
using namespace std;
int main(void) {
	int testCase;
	scanf("%d", &testCase);
	char a[21];		//21������ ũ�⸦ ���� char �迭 a�� ���� �ּҸ� Ȱ���ϸ� �� �迭�� string�� ���� �� �� �ִ�.
	for (int j = 0; j < testCase; j++) {
		int dressNum, b[30] = {0}, result = 1;
		char c[30][21] = {};		//21������ ũ�⸦ ���� char �迭�� 30�� ���� ���� �� �ִ� 2���� �迭�̴�.
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
