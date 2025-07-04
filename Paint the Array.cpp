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
        cin >> n;
        vector<int> a(n);
        rep(i, 0, n) cin >> a[i];
        bool ans1 = true, ans2 = true;
        int gcd1 = 0;
        for (int i = 0; i < n; i += 2)
            gcd1 = __gcd(gcd1, a[i]);
        for (int i = 1; i < n; i += 2)
        {
            if (a[i] % gcd1 == 0)
            {
                ans1 = false;
                break;
            }
        }
        int gcd2 = 0; 
        for (int i = 1; i < n; i += 2)
            gcd2 = __gcd(gcd2, a[i]);
        for (int i = 0; i < n; i += 2)
        {
            if (a[i] % gcd2 == 0)
            {
                ans2 = false;
                break;
            }
        }
        if (ans1 && gcd1 != 0)
            cout << gcd1 << "\n";
        else if (ans2 && gcd2 != 0)
            cout << gcd2 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}