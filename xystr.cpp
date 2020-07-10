#include <iostream>
#include<cstdio>
using namespace std;

int main() {
    int T;
    char S[10000];
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int count=0;
        cin>>S;
        for(int j=0;S[j]!='\0';j+=2)
        {
            if(S[j]=='x' && (S[j+1]=='y' || S[j-1]=='y'))
            {
            	count++;
            	S[j-1]='0';
			}    
            else if(S[j]=='y' && (S[j+1]=='x' || S[j-1]=='x'))
            {
            	count++;
            	S[j-1]='0';
			}   
        }
        cout<<count<<endl;
    }
	return 0;
}

