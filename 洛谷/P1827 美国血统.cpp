#include<iostream>
#include<cstring>
using namespace std;

string s1,s2;

void traverse(int l1,int r1,int l2,int r2){//参数为中序遍历和前序遍历的左右端点 
       if(l1>r1||l2>r2) return;
       char root=s2[l2];
       for(int i=l1;i<=r1;++i)
	    if(s1[i]==root){
       	traverse(l1,i-1,l2+1,l2+i-l1);
       	traverse(i+1,r1,l2+i-l1+1,r2);
       	cout<<root;
	   }
}

int main()
{
	cin>>s1>>s2;
	int len=s1.size()-1;
	traverse(0,len,0,len);
	return 0;
}
