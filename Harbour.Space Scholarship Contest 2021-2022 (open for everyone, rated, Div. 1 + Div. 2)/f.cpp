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
const int N=6e5+20;




struct fenwicktree {
    vector<long long int> bit;
    int n;
    template <typename M>
    fenwicktree(M size){
        n=size+10;
        bit.resize(n);
    }
    
    template <typename M>
    fenwicktree(vector<M> & a){
        n=(int)a.size()+1;
        bit.resize(n);
        for (int i=0; i<n-1; i++) {
            add(i, a[i]);
        }
    }
    
    long long int query(int j){
        long long int ans=0;
        for (++j; j; j-=j&-j) {
            ans+=bit[j];
        }
        return ans;
    }
    long long int query(int i,int j){
        return query(j)-query(i-1);
    }
    
    void add(int id,int val){
        for (++id; id<n; id+=id&-id) {
            bit[id]+=val;
        }
    }
    
};


int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    fenwicktree sum(N), no(N), multiples(N);
    vll ans(n+1);
    ll u;
    for(int i=1; i<=n; i++){
        cin >> u;
        ans[i]+=no.query(0,N)*u-multiples.query(0,(int)u);
        for(int j=(int)u; j<N; j+=u){
            if(u!=1){
                ans[i]+=sum.query(j-(int)u+1, j-1)-no.query(j-(int)u+1, j-1)*(ll)(j-u);
            }
            multiples.add(j,(int)u);
        }
        sum.add((int)u,(int)u);
        no.add((int)u,(int)1);
        ans[i]+=ans[i-1];
    }
    for(int i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }
    cout << el;
    return 0;
}
