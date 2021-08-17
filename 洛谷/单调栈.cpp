#include<iostream>
using namespace std;
const int maxn=3000005;
int num[maxn],order[maxn],ans[maxn],n,top=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i) cin>>num[i];
	for(int i=n;i>=1;--i){
		while(num[i]>=num[order[top]]&&top>0) top--;
		ans[i]=order[top],order[++top]=i;
	}
	for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
	return 0;
}
