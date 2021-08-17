#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e6+10;

long long  next[maxn],len1,len2;
char s1[maxn],s2[maxn];

void getnext(){
	next[0]=-1;
	for(int i=1;i<len1;++i){
		int j=next[i-1];
		while((s2[j+1]!=s2[i])&&j>=0) j=next[j];
	    if(s2[j+1]==s2[i]) next[i]=j+1;
	    else next[i]=-1;
	}
}

int main()
{
   cin>>s1>>s2;	
   len1=strlen(s1);
   len2=strlen(s2);
   getnext();
   
   int i=0,j=0;
   while(i<len1){
   	if(s1[i]==s2[j]){
   		i++,j++;
   		if(len2==j){
   			cout<<i-len2+1<<endl;
   			j=next[j-1]+1;
		   }
	   }
	else{
		if(j==0) ++i;
		else j=next[j-1]+1;
	}
   }
   for(int i=0;i<len2;++i)  
       cout<<next[i]+1<<" ";
      cout<<endl;
    return 0;
}
