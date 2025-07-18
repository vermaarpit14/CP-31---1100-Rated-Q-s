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
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a(n), b(n);
        rep(i, 0, n) cin>>a[i];
        rep(i, 0, n) cin>>b[i];
        vector<int> x(n);
        x[0] = b[0];
        rep(i, 1, n) x[i] = max(x[i-1], b[i]);
        int ans=0, sum=0;
        for(int i=0 ; i<n ; i++){
            if(i == k) break;
            sum += a[i];
            ans = max(ans, sum + (k-i-1)*x[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}