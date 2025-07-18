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

bool f(int mid, vector<int> &h, int x){
    int tot = 0;
    rep(i, 0, h.size()) tot += (h[i] < mid) ? (mid-h[i]) : 0;
    return tot<=x;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //code here
    int t;
    cin>>t;
    while(t--){
        int n, x, ans=0;
        cin>>n>>x;
        vector<int> h(n);
        rep(i, 0, n) cin>>h[i];
        int low=1, high=1e12;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(f(mid, h, x)){
                ans = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}