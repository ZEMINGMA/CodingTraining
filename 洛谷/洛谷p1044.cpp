#define ull unsigned long long
#include<iostream>
using namespace std;
 
void Catlan(){
    int n;
    cin>>n;
    ull f[20];
    f[0]=1;//±ß½çÌõ¼ş
	for(int i=1;i<=n;++i)
	 f[i]=(f[i-1]*(4*i-2))/(i+1);//Catlan
	cout<<f[n];
}

int main()
{
	Catlan();
	return 0;
} 
