#include<iostream>
using namespace std;

const int maxn=1e6+5;
int n,depth=1;

typedef struct node{
	int lchild,rchild;
};

node BiTree[maxn];

void dfs(int index,int dep)
{
    if(0==index) return;
	depth=max(dep,depth);
	
	dfs(BiTree[index].lchild,dep+1);
	dfs(BiTree[index].rchild,dep+1);	
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	 cin>>BiTree[i].lchild>>BiTree[i].rchild;
	dfs(1,1);
	cout<<depth;
	return 0;
}
