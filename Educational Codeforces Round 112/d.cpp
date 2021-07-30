#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <numeric>
#include <deque>
#include <cstring>
#include <iterator>
#include <map>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <complex>
#include <bitset>
#include <chrono>
#include <random>
#include <assert.h>
#include <array>
#include <functional>

using namespace std;

template<typename M, typename N>
istream& operator>>(istream&is, pair<M,N> & p){is >> p.first >> p.second; return is;}
template<typename M>
istream& operator>>(istream&is, vector<M> & v){for(auto &it:v) is >> it; return is; }
template<typename M>
istream& operator>>(istream&is, vector<vector<M>> & v){for(auto &it:v) is >> it; return is; }
template<typename M, typename N>
ostream& operator<<(ostream&os, const pair<M,N> &p){os << p.first << ' ' << p.second << '\n';return os;}
template<typename M>
ostream& operator<<(ostream&os, const vector<M> &v){for(auto it: v)os << it << ' ';cout << '\n';return os;}
template<typename M>
ostream& operator<<(ostream&os, const vector<vector<M>> &v){for(auto it: v)os << it;return os;}

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define mn(x) *min_element((x).begin(),(x).end())
#define mx(x) *max_element((x).begin(),(x).end())
#define acc(x) accumulate((x).begin(),(x).end(),0ll)
#define unique(x) sort(all(x)); x.erase(unique(all(x)),x.end());
#define eb emplace_back
#define el '\n'
typedef  long long  ll;
typedef  unsigned long long  ull;
typedef long double ld;
typedef complex<long double> cd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int a, int b){ return rng()%(b-a+1)+a;}

const ld eps=1e-7;
const ld pi=acos(-1);
const ll inf=(ll)1e9+10;
//const int mod=1000000007;
const int mod=998244353;

int n, m, k;
const int N=100+25;



ll poss[N];

int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s="abc";
    vs v;
    do{
        v.pb(s);
    }while(next_permutation(all(s)));
    for(int i=0; i<6; i++){
        while(v[i].size()<n){
            v[i] = v[i]+v[i];
        }
        v[i] = "#"+v[i];
    }
    cin >> s;
    s = "#" + s;
    vvi dp(n+1, vi(6));
    for(int i=1; i<=n; i++){
        for(int j=0; j<6; j++){
            if(v[j][i]!=s[i]){
                dp[i][j]++;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<6; j++){
            dp[i][j]+=dp[i-1][j];
        }
    }
    for(int i=0, l, r; i<m; i++){
        cin >> l >> r;
        int ans = inf;
        for(int j=0; j<6; j++){
            ans = min(ans, dp[r][j]-dp[l-1][j]);
        }
        cout << ans << el;
    }
    return 0;
}
