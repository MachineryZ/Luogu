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
#include<bits/stdc++.h>
using namespace std;

int n;
int m;
vector<vector<char>> board(105, vector<char>(105, '.'));
int ret;

int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = {-1,1, -1, 0, 1,  -1, 0, 1};

void dfs(int x, int y)
{
    if(x < 0 or x >= n or y < 0 or y >= m or board[x][y] == '.')
        return;
    board[x][y] = '.';
    for(int i = 0; i < 8; i++)
        dfs(x+dx[i], y+dy[i]);
    return;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'W')
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
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/