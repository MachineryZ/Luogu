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

vector<vector<int>> matrix(55, vector<int>(55, -1));
set<vector<int>> mem;

int n;
int m;
int start_x;
int start_y;
int end_x;
int end_y;
char s;
int dir;
int t = 0;
queue<vector<int>> q;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> matrix[i][j];

    cin >> start_x >> start_y >> end_x >> end_y >> s;
    if(s == 'S')
        dir = 1;
    if(s == 'E')
        dir = 0;
    if(s == 'W')
        dir = 2;
    if(s == 'N')
        dir = 3;
    q.push({start_x, start_y, dir});
    mem.insert({start_x, start_y, dir});
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            auto it = q.front();
            q.pop();
            if(it[0] == end_x and it[1] == end_y)
            {
                cout << t << endl;
                return 0;
            }
            int x = it[0];
            int y = it[1];
            int dir = it[2];
            int new_x;
            int new_y;
            int dir;
            if(dir == 0)
            {
                
            }
            if(dir == 1)
            {

            }
            if(dir == 2)
            {

            }
            if(dir == 3)
            {

            }
        }
        t++;
    }
    cout << -1 << endl;
    return 0;
}