#include<bits/stdc++.h>
using namespace std;
int t,n,i,j,p,x,y;
long int ans;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        vector <pair <int,int> > v[10005];
        set <int> st;
        set <int>::iterator it;
        ans=0;
        bool visited[10005] = {false};
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s;
            cin>>p;
            for(j=0;j<p;j++)
            {
                cin>>x>>y;
                x--;
                v[i].push_back({-y,x});
            }
        }
        priority_queue<pair<int,int> >pq;
        for(i=0;i<v[0].size();i++)  pq.push({v[0][i].first,v[0][i].second});
        st.insert(0);
        while(st.size()!=n)
        {
            int vertex,cost;
            while(1)
            {
                vertex = pq.top().second;
                cost = abs(pq.top().first);
                pq.pop();
                if(st.find(vertex)!=st.end());
                else break;
            }
            ans += cost;
            st.insert(vertex);
            // cout<<vertex<<','<<cost<<'\n';
            for(i=0;i<v[vertex].size();i++) pq.push({v[vertex][i].first,v[vertex][i].second});
        }
        cout<<ans<<'\n';
    }
}
