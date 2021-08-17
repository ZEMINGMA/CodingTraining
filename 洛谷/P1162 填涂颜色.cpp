#include<iostream>
const int Max=35;
using namespace std;

int vis[Max][Max]={0};
int n;
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
void dfs(int x,int y){
	if(x<1||y<1||x>n||y>n||vis[x][y]!=0) return;
	vis[x][y]=2;
	for(int i=0;i<4;++i)
	 dfs(x+dx[i],y+dy[i]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=n;++j) 
	  cin>>vis[i][j];
    
    for(int i=1;i<=n;++i)
     dfs(i,1),dfs(i,n);
    for(int j=1;j<=n;j++)
     dfs(1,j),dfs(n,j);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
		 if(vis[i][j]==2) cout<<0<<" ";
		 else if(vis[i][j]==0) cout<<2<<" ";
		 else cout<<vis[i][j]<<" ";
		cout<<endl;	 
	}
	  return 0;
}
