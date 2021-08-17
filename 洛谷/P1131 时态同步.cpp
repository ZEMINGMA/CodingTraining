#include<iostream>
#include<cstring>
using namespace std;
const int maxn=5e5+10;

int n,s;
long long  int father[maxn],tim[maxn];
int r[maxn],edge[maxn],weight[maxn],next[maxn],inde;

void dp(int u,int pre)
{
	long long dis=0,cnt=0,sum=0,num=0;
	for(int i=r[u];i!=-1;i=next[i])
		if(edge[i]!=pre)
		{
			num++;
			dp(edge[i],u);
			sum+=(weight[i]+tim[edge[i]]);
			dis=max(weight[i]+tim[edge[i]],dis);
			cnt+=father[edge[i]]; 
		}
	tim[u]=dis;
	father[u]=dis*num-sum+cnt;
	return ;
}
void build(int a,int b,int t)
{
	edge[inde]=b;
	weight[inde]=t;
	next[inde]=r[a];
	r[a]=inde++;
}

int main()
{
	memset(r,-1,sizeof r);
	 cin>>n>>s;
	for(int i=1;i<n;i++)
	{
		int a,b,t;
		cin>>a>>b>>t;
	  build(a,b,t);
	build(b,a,t);
	}
	dp(s,-1);
	cout<<father[s];
	return 0;
}
