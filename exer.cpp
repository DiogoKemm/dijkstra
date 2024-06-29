#include <bits/stdc++.h>
#define INF numeric_limits<long long>::max();
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    long long n, k;
    cin >> n >> k;
    vector<pair<long long, long long>> adj[n];
    for (long long i = 0; i < k; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }
 
    priority_queue<pair<long long, long long>> q;
    long long distance[n];
    bool processed[n]{};
    for (long long i = 0; i < n; i++)
    {
       distance[i] = INF;
    }
    
    distance[0] = 0;
    q.push({0, 0});
    while (!q.empty())
    {
        long long a = q.top().second;
        q.pop();
        if (processed[a])
            continue;
        processed[a] = true;
        for (auto u : adj[a])
        {
            long long b = u.first, w = u.second;
            if (distance[a] + w < distance[b])
            {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }
 
    for (long long i = 0; i < n; i++)
    {
        cout << distance[i] << " ";
    }
 
    return 0;
}