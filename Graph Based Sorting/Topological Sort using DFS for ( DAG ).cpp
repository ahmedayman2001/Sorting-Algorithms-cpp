    

         /// ( Topological Sort using DFS for ( DAG ) ) : ///




  
#include <bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;


vector<pair<int ,int >>adj[N] ;

bool vis[N] ;

vector<int> order ;



 //// Topological Sort using DFS for ( DAG ) : Directed Acyclic Graph( DAG )  Only ) ///



void dfs ( int u )  {


    cout << u << ' ';
    vis[u] = true ;

    for (auto [v, w] :  adj[u] )

    {
        if (! vis[v] )

            dfs( v) ;
    }

    order.push_back( u ) ;

}




int main() {


    int n , m ;
    cin >> n >> m ;


    //// Adjacency List ////

    for ( int i = 0 , u , v , w ; i < m ; ++i )  {

        cin >> u >> v >> w ;
        adj[u].push_back ( {v , w } ) ;
       // adj[v].push_back ( {u , w } ) ;

    }


    /// Assume DAG ///
    for (int u = 1; u <= n  ; ++u) {

        if ( vis[u] ) continue ;

        dfs(u)  ;

    }

    reverse(order.begin() , order.end() ) ;

    cout <<el ;
    for (auto it : order ) {

        cout<<it<<' ' ;
    }


    return 0 ;
}








