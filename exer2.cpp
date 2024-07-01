#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const long long INF = numeric_limits<long long>::max();
    long long n, k;
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
        {
            break;
        }

        vector<pair<long long, long long>> adj[n];
        for (long long i = 0; i < k; i++)
        {
            long long a, b, c;
            cin >> a >> b >> c;
            a -= 1;
            b -= 1;
            adj[a].push_back({b, c});
            if (adj[b].size() > 0)
            {
                for (auto &edge : adj[b])
                {
                    if (edge.first == a)
                    {
                        edge.second = 0;
                        for (auto &reverseEdge : adj[a])
                        {
                            if (reverseEdge.first == b)
                            {
                                reverseEdge.second = 0;
                            }
                        }
                    }
                }
            }
        }
        long long z;
        cin >> z;
        for (long long i = 0; i < z; i++)
        {
            vector<long long> distance(n, INF);
            priority_queue<pair<long long, long long>> q;
            vector<bool> processed(n, false);
            long long a, b;
            cin >> a >> b;

            a -= 1;
            b -= 1;

            distance[a] = 0;
            q.push({0, a});
            while (!q.empty())
            {
                long long e = q.top().second;
                q.pop();
                if (processed[e])
                    continue;
                processed[e] = true;
                for (auto u : adj[e])
                {
                    long long b = u.first, w = u.second;
                    if (distance[e] + w < distance[b])
                    {
                        distance[b] = distance[e] + w;
                        q.push({-distance[b], b});
                    }
                }
            }
            if (distance[b] != INF)
            {
                cout << distance[b] << "\n";
            }
            else
            {
                cout << "Nao e possivel entregar a carta" << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
