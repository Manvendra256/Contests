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
    int t;
    cin >> t;
    while(t--){
        int W, H, x1, x2, y1, y2, w, h, w_, h_;
        cin >> W >> H;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w >> h;
        w_ = x2-x1;
        h_ = y2-y1;
        if(w_ + w > W && h_ + h > H){
            cout << -1 << el;
        }
        else{
            if(x1>=w || y1>=h || W-x2>=w || H-y2>=h){
                cout << 0 << el;
            }
            else{
                int ans = inf;
                if(w_ + w <=W){
                    ans = min({ans, w-x1, w-W+x2});
                }
                if(h_ + h <=H){
                    ans = min({ans, h-y1, h-H+y2});
                }
                cout << ans << el;
            }
        }
        
    }
    return 0;
}
