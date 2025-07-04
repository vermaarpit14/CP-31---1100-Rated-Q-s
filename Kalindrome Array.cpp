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

bool isPalindrome(const vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; ++i)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            return false;
        }
    }
    return true;
}

bool checkKalindrome(const vector<int> &arr, int x)
{
    vector<int> temp;
    for (int num : arr)
    {
        if (num != x)
        {
            temp.push_back(num);
        }
    }
    return isPalindrome(temp);
}

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
        if (isPalindrome(a))
        {
            cout << "YES\n";
            continue;
        }
        bool possible = false;
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (a[left] != a[right])
            {
                possible = checkKalindrome(a, a[left]) || checkKalindrome(a, a[right]);
                break;
            }
            left++;
            right--;
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }
    return 0;
}