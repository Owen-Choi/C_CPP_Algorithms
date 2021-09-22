#pragma warning(disable:4996)
int  consorvowel(char arr);
int findarr(int index, int num, char printf[], int consN, int vowelN);
#include<stdio.h>
char cons[10];

char vowel[5];

int N = 0;
char arr[16];
int main()
{
    int index = 0;
    int num = 0;
    char print[16] = "";
    int consN = 0;
    int vowelN = 0;
    scanf("%d %d", &N, &num);

    for (int i = 0; i < num; i++)
    {
        scanf(" %c", &arr[i]);
    }
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    findarr(0, 0, print, 0, 0, 0);


    return 0;
}
int  consorvowel(char arr)
{
    if (arr == 'a' || arr == 'e' || arr == 'i' || arr == 'o' || arr == 'u')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int findarr(int index, int num, char print[], int consN, int vowelN)
{
    if (index == N+1)
    {
        if (vowelN > 0 && consN > 1)
        {
            printf("%s\n", print);
        }
        return;
    }
       
        findarr(index, num + 1, print, consN, vowelN);
        if (arr[num] == 'a' || arr[num] == 'e' || arr[num] == 'i' || arr[num] == 'o' || arr[num] == 'u')
        {
            vowelN++;
        }
        else
        {
            consN++;
        }
        print[index] = arr[num];
        findarr(index + 1, num + 1, print, consN, vowelN);
   
}