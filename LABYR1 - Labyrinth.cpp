#include<bits/stdc++.h>
using namespace std;
int t,c,r,i,j,mnx,mny;
char s[1005][1005];
void dfs(int count, int &ans, int x, int y, bool visited[1005][1005])
{
    visited[x][y] = true;
    count++;
    if(count>=ans) { ans= count; mnx=x; mny=y;}
    if(x-1>=0&&!visited[x-1][y]&&s[x-1][y]=='.') 
    {
        // count++;
        dfs(count,ans,x-1,y,visited);
    }
    if(x+1<r&&!visited[x+1][y]&&s[x+1][y]=='.') 
    {
        // count++;
        // if(ans<count) { ans= count; mnx=x; mny=y;}
        dfs(count,ans,x+1,y,visited);
    }
    if(y-1>=0&&!visited[x][y-1]&&s[x][y-1]=='.') 
    {
        // count++;
        // if(ans<count) { ans= count; mnx=x; mny=y;}
        dfs(count,ans,x,y-1,visited);
    }
    if(y+1<c&&!visited[x][y+1]&&s[x][y+1]=='.') 
    {
        // count++;
        // if(ans<count) { ans= count; mnx=x; mny=y;}
        dfs(count,ans,x,y+1,visited);
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>c>>r;
        for(i=0;i<r;i++) for(j=0;j<c;j++) cin>>s[i][j];
        int ans = 0, count=0;
        bool visited[1005][1005] = {false};
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(s[i][j]=='.'&&!visited[i][j])
                    dfs(count,ans,i,j,visited);
            }
        }
        for(i=0;i<1005;i++) for(j=0;j<1005;j++) visited[i][j]=false;
        dfs(0,ans,mnx,mny,visited);
        
        cout<<"Maximum rope length is "<<ans-1<<".\n";
        // if(ans==0)  cout<<ans<<".\n";
        // else cout<<ans-1<<".\n";
    }
}