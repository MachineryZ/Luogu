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

vector<vector<char>> board(1005, vector<char>(1005 , ' '));
int n;
int m;
int S;

pair<int, int> find(int x, int y)
{
    int i;
    int j;
    for(i = x; i <= n; i++)
        if(board[i][y] != '#')
            break;
    for(j = y; j <= m; j++)
        if(board[x][j] != '#')
            break;
    i--;
    j--;
    return {i, j};
}

void check(int x, int y, int& area)
{
    if(x < 0 or x >= n or y < 0 or y >= m or board[x][y] != '#')
        return;
    // cout << x << " " << y << " " << board[x][y] << " " << area << endl;
    area += 1;
    board[x][y] = '.';
    check(x+1, y, area);
    check(x-1, y, area);
    check(x, y+1, area);
    check(x, y-1, area);
    return;
}

int main()
{
    cin >> n;
    cin >> m;
    
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++)
            board[i][j] = str[j];
    } 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == '#')
            {
                pair<int, int> p = find(i, j);
                // cout << i << " " << j << " " << p.first << " " << p.second << endl;
                int area = 0;
                check(i, j, area);
                if(area != (p.first - i + 1) * (p.second - j + 1))
                {
                    cout << "Bad placement." << endl;
                    return 0;
                }
                S++;
            }
        }
    }
    cout << "There are " << S << " ships." << endl;
    return 0;
}
/*
6 8
.....#.#
##.....#
##.....#
.......#
#......#
#..#...#

3 5
#..##
.##.
#...#
*/