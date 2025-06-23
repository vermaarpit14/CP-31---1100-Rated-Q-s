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
        int n, k, a, b;
        cin>>n>>k>>a>>b;
        vector<pair<int, int>> pos(n);
        rep(i, 0, n) cin>>pos[i].first>>pos[i].second;
        pair<int, int> start = {pos[a-1].first, pos[a-1].second};
        pair<int, int> end = {pos[b-1].first, pos[b-1].second};
        int mn = abs(start.first - end.first) + abs(start.second - end.second);
        int mn1=LLONG_MAX/2, mn2=LLONG_MAX/2;
        if(k >= 2){
            rep(i, 0, k) mn1 = min(mn1, abs(start.first - pos[i].first) + abs(start.second - pos[i].second));
            rep(i, 0, k) mn2 = min(mn2, abs(end.first - pos[i].first) + abs(end.second - pos[i].second));
        }
        mn = min(mn, mn1+mn2);
        cout<<mn<<"\n";
    }
    return 0;
}