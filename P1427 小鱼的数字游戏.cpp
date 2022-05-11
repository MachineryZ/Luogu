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


int main()
{
    vector<int> ret;
    int a;
    while(true)
    {
        cin >> a;
        if(a == 0)
            break;
        ret.push_back(a);
    }
    for(auto it = ret.rbegin(); it != ret.rend(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}
/*
3 65 23 5 34 1 30 0
*/