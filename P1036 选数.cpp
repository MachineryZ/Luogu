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

vector<int> x(21);
unordered_set<int> prime;
int ret = 0;

void addprime(int x)
{
    prime.insert(2);
    for(int num = 3; num < x; num++)
    {
        bool isprime = true;
        for(auto it : prime)
        {
            if(num % (it) == 0)
            {
                isprime = false;
                break;
            }
        }
        if(isprime == true)
            prime.insert(num);
        // cout << num << " " << isprime << endl;
    }
    return;
}

void dfs(int n, int k, int already_k, int index, int sum)
{
    if(already_k == k)
    {
        if(prime.find(sum) != prime.end())
        {
            ret++;
            return;
        }
    }
    if(index >= n)
        return;
    dfs(n, k, already_k, index+1, sum);
    dfs(n, k, already_k+1, index+1, sum+x[index]);
    return;
}

int main()
{
    int n;
    int k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> x[i];
    addprime(std::accumulate(x.begin(), x.begin()+n, 0));
    dfs(n, k, 0, 0, 0);
    cout << ret << endl;
    return 0;
}
/*
4 3
3 7 12 19
*/