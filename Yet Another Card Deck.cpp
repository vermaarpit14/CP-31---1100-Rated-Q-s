/************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define each(x, a) for (auto &x : a)

const int INF = 1e18;
const int MOD = 1e9 + 7;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
/************************************************************************************/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int n, q;
    cin>>n>>q;
    vector<int> f(51, n+1);
    for(int i=1 ; i<=n ; i++){
        int x; cin>>x;
        if(f[x] == n+1){
            f[x] = i;
        }
    }
    while(q--){
        int t; cin>>t;
        cout<<f[t]<<" ";
        for(int i=0 ; i<=50 ; i++){
            if(f[i] < f[t])
            f[i] += 1;
        }
        f[t] = 1;
    }
    cout<<"\n";
    return 0;
}