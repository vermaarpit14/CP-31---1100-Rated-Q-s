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
        int n, x;
        cin>>n>>x;
        vector<int> a(n), b(n), c(n);
        rep(i, 0, n) cin>>a[i];
        rep(i, 0, n) cin>>b[i];
        rep(i, 0, n) cin>>c[i];
        int x1=0, x2=0, x3=0;
        for(int i=0 ; i<n ; i++){
            if((x|a[i]) != x)
            break;
            x1 = x1|a[i];
        }
        for(int i=0 ; i<n ; i++){
            if((x|b[i]) != x)
            break;
            x2 = x2|b[i];
        }
        for(int i=0 ; i<n ; i++){
            if((x|c[i]) != x)
            break;
            x3 = x3|c[i];
        }
        if((x1|x2|x3)==x)
        cout<<"Yes"<<"\n";
        else
        cout<<"No"<<"\n";
    }
    return 0;
}