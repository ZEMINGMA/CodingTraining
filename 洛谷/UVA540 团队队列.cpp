#include<iostream>
#include<string> 
using namespace std;
const int maxn=1005;

struct Team{
	int flag;//判断当前队列中是否存在该团队人员 
	int head=0,tail=0;//每个团队的首尾指针 
	int member[maxn]; //每个团队当前在队列中的顺序 
}q[maxn];
int tq[maxn],hea=0,tai=0;//表示团队的队列
int ident[1000005];//表示编号为某个值的人所在团队的编号
string order;

int main()
{
	int t,kase=0;
	while(cin>>t&&t!=0){
		cout<<"Scenario #"<<++kase<<endl;
		
		for(int i=1;i<=t;++i){
			int n,x;//n表示每个团队的人数，x表示编号为x的人
			cin>>n;
			while(n--){
				cin>>x;
				ident[x]=i;//编号为x的人在团队i 
			} 
		}
		for(;;){
		  int x;
		  cin>>order;
          if(order=="STOP") break;
          else if(order=="ENQUEUE"){
          	cin>>x;
          	if(q[ident[x]].flag==0) q[ident[x]].flag=1,tq[++tai]=ident[x];
          	q[ident[x]].member[++q[ident[x]].tail]=x;
		  }
		  else if(order=="DEQUEUE"){
		  	cout<<q[tq[hea+1]].member[++q[tq[hea+1]].head]<<endl;
		  	if(q[tq[hea+1]].head==q[tq[hea+1]].tail) q[tq[hea+1]].flag=0,hea++;
		  }
	  }
	  hea=tai=0;
	  for(int i=1;i<maxn;++i)
	  {
	  	q[i].flag=0;
	  	q[i].head=q[i].tail=0;
	  }
	  cout<<endl;
	} 
	return 0;
} 
