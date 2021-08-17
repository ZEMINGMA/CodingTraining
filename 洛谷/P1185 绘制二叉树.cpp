#include<iostream>
#include<cstring>
using namespace std;
const int maxn=2048+5;

char tree[maxn][maxn];
bool vis[maxn][maxn]={0};
int n,m,flag,x,y;

void build(int x,int y,int start,int end,int flag,int p,int q)
{
	if(x==n) {
		tree[x][y]='o';
		return;
	}
	if(flag==1){
		tree[x][y]='o';
		if(!vis[p+1][(q-1)*2+1]) build(x+1,y-1,start+1,end,2,p+1,(q-1)*2+1);
		if(!vis[p+1][q*2]) build(x+1,y+1,start+1,end,3,p+1,q*2);
	}
	else if(flag==2){
		tree[x][y]='/';
		if(start*2==end) build(x+1,y-1,1,start,1,p,q);
		else             build(x+1,y-1,start+1,end,2,p,q);
	}
	else if(flag==3){
		tree[x][y]='\\'; 
		if(start*2==end) build(x+1,y+1,1,start,1,p,q);
		else             build(x+1,y+1,start+1,end,3,p,q);
	}
}

int main()
{
	memset(tree,' ',sizeof(tree));
	cin>>m>>n;
	while(n--)
	 cin>>x>>y,vis[x][y]=1;
	if(m==1)
	 n=m=1,tree[1][1]='o';
	else
	 {
	 	
	 	int a=m,b=n;n=3;
	 	for(int i=3;i<=a;++i) n*=2;
	 	m=(1<<(a-2))*6-1;
	 	build(1,m/2+1,1,n,1,1,1);
	 }
	 for(int i=1;i<=n;++i)
	 {
	 	 for(int j=1;j<=m;++j) cout<<tree[i][j];
	 	 cout<<endl;
	 }
	 
	   
}
