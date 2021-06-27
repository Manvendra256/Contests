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
const int N=1e2+5;

struct mint{
    ll x;
    mint(){};
    mint(ll xx) : x(xx) {}
    mint operator+(const mint & b) { return x+b.x>=mod?x+b.x-mod:x+b.x; }
    mint operator-(const mint & b) { return x>=b.x?x-b.x:x-b.x+mod; }
    mint operator*(const mint & b) { return x * b.x % mod; }
    mint operator/(const mint & b) { return *this * inverse(b); }
    mint operator+=(const mint & b) {return *this = *this+b;}
    mint operator-=(const mint & b) {return *this = *this-b;}
    mint operator*=(const mint & b) {return *this = *this*b;}
    mint operator/=(const mint & b) {return *this = *this/b;}
    bool operator==(const mint &b) {return x==b.x;}
    bool operator!=(const mint &b) {return x!=b.x;}
    bool operator<(const mint &b) {return x<b.x;}
    bool operator>(const mint &b) {return x>b.x;}
    mint operator++(){return *this = *this+1;}
    mint operator--(){return *this = *this-1;}
    mint operator-(){return x?mod-x:0;}
    mint operator^(ll e) {
        mint r=1;
        mint xx=x;
        while(e){
            if(e&1)r*=xx;
            xx*=xx;
            e>>=1;
        }
        return r;
    }
    mint inverse(mint a) {
        return a^(mod-2);
    }
    friend ostream& operator<<(ostream & os, const mint & m){os << m.x;return os;}
    friend istream& operator>>(istream & in, mint & m){in >> m.x; return in;}
};


mint dp[N][N*N];
mint new_dp[N][N*N];
mint f[N];

int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    dp[0][0]=1;
    f[0]=1;
    for(int i=1; i<N; i++){
        f[i] = f[i-1]*i;
    }
    int sum=0;
    for(int i=0, u; i<n; i++){
        cin >> u;
        sum+=u;
        memset(new_dp, 0, sizeof(new_dp));
        new_dp[0][0]=1;
        for(int j=1; j<=n; j++){
            for(int k=1; k<=sum; k++){
                new_dp[j][k]+=dp[j][k];
                if(k>=u)
                    new_dp[j][k]+=dp[j-1][k-u];
            }
        }
        swap(dp, new_dp);
    }
    if(sum&1){
        cout << 0 << el;
        return 0;
    }
    sum/=2;
    mint ans=0;
    for(int i=1; i<n; i++){
        ans+=f[i]*f[n-i]*dp[i][sum];
    }
    cout << ans << el;
    return 0;
}


