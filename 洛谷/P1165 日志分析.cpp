#include<iostream>
const int maxn=2000005;
using namespace std;
int n,weight[maxn],top=0,m[maxn],top2=0; //引入一个辅助栈，记录当前的最大值 
void findmax(){//找最大值
    if(top2==0||weight[top]>m[top2-1])
     m[top2]=weight[top],top2++;
    else
     m[top2]=m[top2-1],top2++;
}
int main()
{
   cin>>n;
   int order;//输入的操作数 
   for(int i=1;i<=n;++i){
   	cin>>order;
   	if(order==0)cin>>weight[top],findmax(),top++; //输入的操作数是0  
    if(order==1&&top!=0) top--,top2--;//输入的操作数是1
	if(order==2) 
	   if(top2==0) cout<<0<<endl;
	   else cout<<m[top2-1]<<endl;//输入的操作数是2 输出查询结果  		
   }	
	
}
