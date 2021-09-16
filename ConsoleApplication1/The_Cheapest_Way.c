#include<stdio.h>
#include<stdlib.h>

int Row, Col;
void Solve(int** Input, int** dp);
void FindIndex(int** dp, int ChangedRow, int ChangedCol);
void FindMinValue(int** dp);
int FindMin(int first, int last);

int main() {
	FILE* fp;
	fp = fopen("C:\\Users\\oldst\\Desktop\\201835539 √÷√∂øı\\Input3.txt", "r");
	if (fp == NULL) {
		printf("Cannot find any files \n");
		exit(1);
	}
	// :: First, we have to read Row and Col value to dynamically allocate 2d array's size.
	fscanf(fp, "%d %d\n", &Row, &Col);
	int** Input = (int**)malloc(sizeof(int*) * Row + 1);
	int** dp = (int**)malloc(sizeof(int*) * Row + 1);
	for (int i = 0; i <= Row; i++) {
		Input[i] = (int*)malloc(sizeof(int) * (Col + 1));
	} 
	for (int i = 0; i <= Row; i++) {
		dp[i] = (int*)malloc(sizeof(int) * (Col + 1));
	}
	//done :: 
	// :: Read Input and Initialize dp array
	for (int i = 1; i <= Row; i++) {
		for (int k = 1; k <= Col; k++) {
			fscanf(fp, "%d", &Input[i][k]);
			dp[i][k] = 0;
		}
	}
	//done ::
    Solve(Input, dp);
    FindMinValue(dp);
	return 0;
}

void Solve(int** Input, int** dp) {
	int tempUpper, tempDown, tempLeft;
	int Min;
	for (int k = 1; k <= Row; k++)
		dp[k][1] = Input[k][1];
	for (int k = 2; k <= Col; k++) {
		for (int i = 1; i <= Row; i++) {
			if (i == 1 || i == Row) {
				if (i == 1) {
					tempUpper = dp[Row][k - 1];
					tempDown = dp[i + 1][k - 1];
				}
				else {
					tempUpper = dp[Row - 1][k - 1];
					tempDown = dp[1][k - 1];
				}
			}
			else {
				tempUpper = dp[i - 1][k - 1];
				tempDown = dp[i + 1][k - 1];
			}
			tempLeft = dp[i][k - 1];
			Min = FindMin(tempUpper, tempDown);
			Min = FindMin(Min, tempLeft);
			dp[i][k] = Min + Input[i][k];
		}
	}
}

void FindIndex(int** dp, int ChangedRow, int ChangedCol) {
	int* IndexArr = (int*)malloc(sizeof(int) * Col);
    int tempUpper, tempDown, tempLeft, Min, iter = 0;
    while (ChangedRow > 0 && ChangedCol > 0) {
        if (ChangedCol == 1) {
            IndexArr[iter++] = dp[ChangedRow][ChangedCol];
            break;
        }
        if (ChangedRow == Row || ChangedRow == 1) {
            if (ChangedRow == 1) {
                tempUpper = dp[Row][ChangedCol - 1];
                tempDown = dp[2][ChangedCol - 1];
            }
            else {
                tempUpper = dp[ChangedRow - 1][ChangedCol - 1];
                tempDown = dp[1][ChangedCol - 1];
            }
        }
        else {
            tempUpper = dp[ChangedRow - 1][ChangedCol - 1];
            tempDown = dp[ChangedRow + 1][ChangedCol - 1];
        }
        tempLeft = dp[ChangedRow][ChangedCol - 1];
        Min = FindMin(tempUpper, tempDown);
        Min = FindMin(Min, tempLeft);
        IndexArr[iter++] = dp[ChangedRow][ChangedCol] - Min;
        if (Min == tempUpper) {
            if (ChangedRow == 1 || ChangedRow == Row) {
                if (ChangedRow == 1) {
                    ChangedRow = Row;
                    ChangedCol--;
                }
                else {
                    ChangedRow = Row - 1;
                    ChangedCol--;
                }
            }
            else {
                ChangedRow--;
                ChangedCol--;
            }
        }
        else if (Min == tempDown) {
            if (ChangedRow == 1 || ChangedRow == Row) {
                if (ChangedRow == 1) {
                    ChangedRow = 2;
                    ChangedCol--;
                }
                else {
                    ChangedRow = 1;
                    ChangedCol--;
                }
            }
            else {
                ChangedRow++;
                ChangedCol--;
            }
        }
        else {
            ChangedCol--;
        }
    }
    for (int i = Col - 1; i >= 0; i--)
        printf("%d ", IndexArr[i]);
    printf("\n");
}

void FindMinValue(int** dp) {
    int Min = dp[1][Col];

    for (int i = 2; i <= Row; i++) {
        Min = FindMin(Min, dp[i][Col]);
    }
    for (int i = 1; i <= Row; i++) {
        if (dp[i][Col] == Min) {
            FindIndex(dp, i, Col);
            printf("%d\n", Min);
            return;
        }
    }
}

int FindMin(int first, int last) {
	return first < last ? first : last;
}