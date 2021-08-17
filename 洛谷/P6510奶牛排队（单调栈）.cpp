#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100005;

int n,ans,k;
int arr[maxn],s1[maxn],s2[maxn],top1,top2;//arr保存输入 s1为单调递减栈，s2为单调递增栈，top1 top2分别为栈顶元素指针 
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	 cin>>arr[i];//输入初始化 
	
	for(int i=1;i<=n;++i){
	while(top1&&arr[s1[top1]]>=arr[i]) top1--;
	while(top2&&arr[s2[top2]]<arr[i])  top2--;//分别维护两个栈 
	k=upper_bound(s1+1,s1+1+top1,s2[top2])-s1;//在s1中查找一个比后缀第二个值大 
	if(k!=(top1+1)) ans=max(ans,i-s1[k]+1);//如果存在则更新 
	
	s1[++top1]=i;
	s2[++top2]=i;	 
    }
    cout<<ans;
    return 0;
}
