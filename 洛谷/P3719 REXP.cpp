#include<iostream>
#include<algorithm>
using namespace std;

int func(int ans)
{
	char s;
	while(cin>>s){
		if(s=='a') ans++;
		if(s=='(') ans=ans+func(0);
		if(s=='|') return max(ans,func(0));
		if(s==')') return ans;
	}
    return ans;
}

int main()
{
	cout<<func(0);
	return 0;
}
