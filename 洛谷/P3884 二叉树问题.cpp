#include<iostream>
using namespace std;
const int maxn=105;

int n;//二叉树结点的个数
int u,v;//所求的两点 
int x,y;//表示y是x的孩子 
int depth=0,width=0,dep[maxn],wid[maxn],father[maxn];//表示深度和宽度和祖先 
int upstep=0,downstep=0;//上行的步数 下行的步数 

int main()
{
	cin>>n;
	for(int i=1;i<n;++i){
		cin>>x>>y;
		father[y]=x;//y的父亲是x
		dep[y]=dep[x]+1;//y的层数比x多1
		wid[dep[y]]++;//宽度加一
		depth=max(depth,dep[y]);
		width=max(width,wid[dep[y]]); 
	}//构建二叉树
	
	cin>>u>>v;
	while(u!=v){
		if(dep[u]==dep[v])//如果层数相同
		 {
		 	u=father[u];
		 	v=father[v];
		 	upstep++;
		 	downstep++;
		 }
		 else if(dep[u]>dep[v]){
		 	u=father[u];
		 	upstep++;
		 }
		 else{
             v=father[v];
			 downstep++;		 	
		 }
	}
	 cout<<depth+1<<endl<<width<<endl<<upstep*2+downstep;
	 return 0;
	}
