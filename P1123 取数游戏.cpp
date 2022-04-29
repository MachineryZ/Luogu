#include<bits/stdc++.h>//万能头文件 
using namespace std;
const int d[8][2]={1,0,-1,0,0,1,0,-1,1,1,-1,1,1,-1,-1,-1};//方向数组用来控制搜索时的方向 
int t,n,m,s[8][8],mark[8][8],ans,mx;
void dfs(int x,int y){//搜索函数，表示搜索点(x,y) 
	if(y==m+1){//当y到边界时，搜索下一行 
		dfs(x+1,1);
		return;
	}
	if(x==n+1){//当x到边界时，搜索结束，刷新最大值 
		mx=max(ans,mx);
		return;
	}
	
	dfs(x,y+1);// 不取此数的情况 
	
	if(mark[x][y]==0){ //取此数的情况（需保证此数周围没有取其他数，即mark[i][j]==0）
		ans+=s[x][y];
		for(int fx=0;fx<8;++fx){ //标记周围的数 
			++mark[x+d[fx][0]][y+d[fx][1]];
		}
		dfs(x,y+1);
		for(int fx=0;fx<8;++fx){ //回溯 
			--mark[x+d[fx][0]][y+d[fx][1]];
		}
		ans-=s[x][y];
	}
	
}
int main(){
	cin>>t; 
	while(t--){
		memset(s,0,sizeof(s));
		memset(mark,0,sizeof(mark));//在做每个数据前都要初始化数组 
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>s[i][j];
			}
		}
		mx=0;
		dfs(1,1);//从点(1,1)开始搜索 
		printf("%d\n",mx);//输出答案 
	}
	return 0;
}
/*
3
4 4
67 75 63 10
29 29 92 14
21 68 71 56
8 67 91 25
2 3
87 70 85
10 3 17
3 3
1 1 1
1 99 1
1 1 1
*/