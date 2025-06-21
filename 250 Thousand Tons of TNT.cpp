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

vector<bool> sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
/************************************************************************************/

vector<int> getDivisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // code here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + a[i];
        vector<int> divisors = getDivisors(n);
        int max_diff = 0;
        for (int k : divisors)
        {
            if (k == n)
                continue;
            int max_sum = LLONG_MIN, min_sum = LLONG_MAX;
            for (int i = 1; i <= n / k; ++i)
            {
                int sum = prefix[i * k] - prefix[(i - 1) * k];
                max_sum = max(max_sum, sum);
                min_sum = min(min_sum, sum);
            }
            max_diff = max(max_diff, max_sum - min_sum);
        }

        cout << max_diff << "\n";
    }
    return 0;
}