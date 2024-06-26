struct Edge 
{
    int u, v, c;
    Edge( int U, int V, int C ) 
    {
        u = U,
        v = V,
        c = C;
    }
};

int n, m;
vector<Edge> edges;

ll bellman( int root ) 
{
    vector<ll> dist(n + 1, oo);
    dist[root] = 0;

    bool flag = true;
    int cnt = 0; // if cnt > n - 1 there is a negative cycle
    
    while(flag) 
    {
        cnt++;
        flag = false;
        for( Edge e : edges )
            if(dist[e.v] != oo && dist[e.u] > dist[e.v] + e.c)
                dist[e.u] = dist[e.v] + e.c, flag = true;

        if(cnt > n) break;
    }

    if( cnt > n ) return -oo;

    return *min_element(dist.begin(), dist.end());
}