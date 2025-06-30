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
        string s;
        cin>>s;
        int n = s.length(), mx = 0;
        int cnt = 0;
        for(int i=0 ; i<n ; i++){
            if(s[i] == '1'){
                cnt += 1;
                mx = max(mx, cnt);
            }
            else
                cnt = 0;
        }
        if(cnt == n){
            cout<<n*n<<"\n";
            continue;
        }
        if(s[0]=='1' && s[n-1]=='1'){
            int cnt1=0, cnt2=0;
            int i=0, j=n-1;
            while(i<n && s[i]=='1'){
                cnt1 += 1;
                i += 1;
            }
            while(j>=0 && s[j]=='1'){
                cnt2 += 1;
                j -= 1;
            }
            if(i <= j)
            mx = max(mx, cnt1+cnt2);
        }
        cout<<((mx+1)/2)*((mx+2)/2)<<"\n";
    }
    return 0;
}