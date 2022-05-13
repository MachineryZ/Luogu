#include<bits/stdc++.h>
using namespace std;
int i,j,n,a[1001],dp[1001];
int main()
{	cin>>n;//输入
	for(i=1;i<=n/2;i++)
		for(j=2;i*j<=n;j++)
			a[i*j]+=i;//预处理
	for(i=1;i<=n;i++)//循环n个数
		for(j=i;j<=n;j++)
			dp[j]=max(dp[j],dp[j-i]+a[i]);//取或不取
	cout<<dp[n];//输出
  	return 0;
}