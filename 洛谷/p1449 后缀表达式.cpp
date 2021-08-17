#include<iostream>
#include<cstring> 
using namespace std;

char order[1005];
int num[1005];
int main()
{
	cin>>order;
	int len=strlen(order);
	int j=0;
	for(int i=0;i<len;++i)
	    if(isdigit(order[i])) 
	     {
	     	int temp;
	     	 temp=order[i]-'0';
	     	while(isdigit(order[++i]))
	     	 temp=temp*10+order[i]-'0';
	     	num[j]=temp,++j;//ÅÐ¶ÏÊÇ·ñÊÇÊý×Ö
	     	--i;
		 }
	 	else if(order[i]=='+')
	 	  num[j-2]=num[j-2]+num[j-1],j--;
	 	else if(order[i]=='-')
	 	  num[j-2]=num[j-2]-num[j-1],j--;
	 	else if(order[i]=='*')
	 	  num[j-2]=num[j-2]*num[j-1],j--;
	 	else if(order[i]=='/')
	 	  num[j-2]=num[j-2]/num[j-1],j--;
	 cout<<num[0];
	return 0;
}
