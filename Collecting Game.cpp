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

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t;
    cin>>t;
    while(t--){
        int n, sum=0;
        cin>>n;
        vector<int> a(n), pre(n);
        rep(i, 0, n) cin>>a[i];
        vector<pair<int, int>> b(n);
        rep(i, 0, n) b[i] = {a[i], i};
        sort(all(b), cmp);
        rep(i, 0, n) {
            sum += b[i].first;
            pre[i] = sum;
        }
        vector<int> ans(n);
        int last = n-1;
        ans[b[n-1].second] = n-1;
        for(int i=n-2 ; i>=0 ; i--){
            if(pre[i] < b[i+1].first)
            last = i;
            ans[b[i].second] = last;
        }
        rep(i, 0, n) cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}