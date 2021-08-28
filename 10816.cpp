#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n";

using namespace std;

int N, M;
vector<int> x(20000001);

int main()
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> index;
        if (index < 0)
            index = 10000000 - index;
        x[index]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> index;
        if (index < 0)
            index = 10000000 - index;
        cout << x[index] << " ";
    }

    return 0;
}