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
        int n;
        cin>>n;
        vector<int> a(n), l(n), r(n);
        rep(i, 0, n) cin>>a[i];
        l[0] = a[0];
        rep(i, 1, n) l[i] = l[i-1]+a[i];
        r[n-1] = a[n-1];
        per(i, 0, n-1) r[i] = r[i+1]+a[i];
        int i=0, j=n-1;
        pair<int, int> ans = {0, 0};
        while(i < j){
            if(l[i] < r[j])
            i += 1;
            else if(l[i] > r[j])
            j -= 1;
            else{
                ans = {i+1, n-j};
                i += 1;
                j -= 1;
            }
        }
        cout<<ans.first+ans.second<<"\n";
    }
    return 0;
}