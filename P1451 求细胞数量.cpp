#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

vector<vector<int>> matrix(105, vector<int>(105, 0));
int ret;
int n;
int m;

void dfs(int x, int y)
{
    if(x < 0 or x >= n or y < 0 or y >= m or matrix[x][y] == 0)
        return;
    matrix[x][y] = 0;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y+1);
    dfs(x, y-1);
    return;
}

int main()
{
    cin >> n >> m;
    string str;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        for(int j = 0; j < m; j++)
            matrix[i][j] = str[j] - '0';
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] != 0)
            {
                ret++;
                dfs(i, j);
            }
        }
    }
    cout << ret << endl;
    return 0;
}
/*

4 10
0234500067
1034560500
2045600671
0000000089
*/