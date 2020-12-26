#include<bits/stdc++.h>
using namespace std;
int n,i,t,j;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        string prefix[10005],suffix[10005];
        prefix[0]=s[0];
        for(i=1;s[i];i++)
        {
            prefix[i] = prefix[i-1] + s[i];
        }
        suffix[i-1]=s[i-1];
        // cout<<i-2<<suffix[i-1]<<'\n';
        for(j=i-2;j>=1;j--)
        {
            suffix[j] = s[j] + suffix[j+1];
        }
        int pos=1;
        // for(i=0;s[i];i++)   cout<<prefix[i]<<'\n';
        // for(i=1;s[i];i++)   cout<<suffix[i]<<'\n';
        string h = suffix[0]+prefix[i-1];
        // cout<<h<<'\n';
        for(i=1;i<s.length();i++)
        {
            string p = suffix[i] + prefix[i-1];
            // cout<<p<<'\n';
            if(p<h) { pos = i+1; h=p; }
        }
        // if(prefix[i]<=h) pos=1;
        cout<<pos<<'\n';
    }
}