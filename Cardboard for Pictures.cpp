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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> s(n);
        int sum = 0, sq = 0;
        rep(i, 0, n)
        {
            cin >> s[i];
            sum += s[i];
            sq += s[i] * s[i];
        }
        int low = 1, high = sqrt(c / (4 * n)) + 2;
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int term = 4 * mid * sum;
            int term2 = 4 * n * mid * mid;
            if (term > c - sq - term2)
            {
                high = mid - 1;
            }
            else if (sq + term + term2 < c)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}