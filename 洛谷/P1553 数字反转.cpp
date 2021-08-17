#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char str[25];

void Reverse(char s[])
{
	int tail=0;
	while(isdigit(s[tail])) tail++;
	tail--;
	int head=0;
	while(s[tail]=='0'&&tail>0) tail--;//去除后导0 
    while(s[head]=='0'&&tail>0) ++head;//去除前导0
	for(;tail>=head;--tail) 
	   cout<<s[tail];
}

int main()
{
	int i=0,j,k;
	char s1[25],s2[25];
    while(cin>>str[i]) i++;//输入 
	int l=strlen(str)-1; 
	
    for(j=0;j<=l;++j)
      if(isdigit(str[j])) s1[j]=str[j];
      else break;
    Reverse(s1);
      if(j<=l) cout<<str[j++];
   
	  
	if(str[j-1]=='/'||str[j-1]=='.'){
	for(k=0;j<=l;) 
	   s2[k]=str[j],j++,k++;
     Reverse(s2);
	  } 
   
	return 0;
}
