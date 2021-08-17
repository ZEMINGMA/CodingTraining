#include<iostream>
#include<string>
using namespace std;

string str;
int n;

void build(string s)
{
	int len=s.size();
	if(len>=2){
		 build(s.substr(0,len/2));
		 build(s.substr(len/2,len));
	}
	if(s==string(len,'0')) cout<<'B';
	else if(s==string(len,'1')) cout<<'I';
	else cout<<'F';
}

int main()
{
	cin>>n>>str;
	build(str);
	return 0;
}
