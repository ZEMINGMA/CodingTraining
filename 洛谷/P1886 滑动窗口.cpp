#include<iostream>
using namespace std;
const int maxn=1000005;

int a[maxn];//序列a
int index[maxn];//单调序列存储a的下标
int n,k;//n为序列个数 k为窗口长度 

void MIN(){
   	int head=1,tail=0;//单调队列的首尾指针
	for(int i=1;i<=n;++i){
		while(head<=tail&&index[head]+k<=i) head++;//保证单调队列的长度小于窗口长度
        while(head<=tail&&a[i]<a[index[tail]]) tail--;//若入队的值更小 则出队
		index[++tail]=i;//入队
		if(i>=k) cout<<a[index[head]]<<" ";	 
	} 
} 

void MAX(){
	int head=1,tail=0;//单调队列的首尾指针
	for(int i=1;i<=n;++i){
		while(head<=tail&&index[head]+k<=i) head++;//保证单调队列的长度小于窗口长度
        while(head<=tail&&a[i]>a[index[tail]]) tail--;//若入队的值更大 则出队
		index[++tail]=i;//入队
		if(i>=k) cout<<a[index[head]]<<" ";	 
	} 
	
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	MIN();
	cout<<endl;
	MAX();
	return 0;
}
