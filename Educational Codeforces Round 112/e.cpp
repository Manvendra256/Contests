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

struct lazy_segtree {
    struct node{
        ll min,max,sum,sz,lazy;
        bool set;
        node() : set(false), lazy(0), min(0), max(0), sum(0), sz(0){};
        void push(node & a, node & b){
            if(this->set==true){
                a.min=this->min; a.max=this->max; a.sum=a.sz*this->min; a.set=true;
                b.min=this->min; b.max=this->max; b.sum=b.sz*this->min; b.set=true;
                this->lazy=0;
                this->set=false;
            }
            else{
                a.min+=this->lazy;a.max+=this->lazy;a.sum+=a.sz*this->lazy;a.lazy+=this->lazy;
                b.min+=this->lazy;b.max+=this->lazy;b.sum+=b.sz*this->lazy;b.lazy+=this->lazy;
                this->lazy=0;
            }
        }
        
    };
    vector<node> st;
    int n;
    
    void push(int u){
        st[u].push(st[2*u],st[2*u+1]);
    }

    lazy_segtree(int m){
        n=(int)m+10;
        st.resize(4*n);
    }
    
    void combine(node &a,node &b,node &c){
        a.sum=b.sum+c.sum;
        a.min=min(b.min, c.min);
        a.max=max(b.max,c.max);
    }
    node query(int v,int l,int r,int l_,int r_){
        if (l==l_&&r==r_) {
            return st[v];
        }
        push(v);
        int m=(l+r)/2;
        if (r_<=m) {
            return query(2*v, l, m, l_, r_);
        }
        else if (l_>m){
            return query(2*v+1, m+1, r, l_, r_);
        }
        else{
            node a,b,c;
            b=query(2*v, l, m, l_, m);
            c=query(2*v+1, m+1, r, m+1, r_);
            combine(a, b, c);
            return a;
        }
    }
    void add(int v,int l,int r,int l_,int r_,int k){
        if (l==l_&&r==r_) {
            st[v].sum+=st[v].sz*k;
            st[v].min+=k;
            st[v].max+=k;
            st[v].lazy+=k;
            return ;
        }
        push(v);
        int m=(l+r)/2;
        if (r_<=m) {
            add(2*v, l, m, l_, r_, k);
        }
        else if (l_>m){
            add(2*v+1, m+1, r, l_, r_, k);
        }
        else{
            add(2*v, l, m, l_, m, k);
            add(2*v+1, m+1, r, m+1, r_, k);
        }
        combine(st[v], st[2*v], st[2*v+1]);
    }
    
    void set(int v,int l,int r,int l_,int r_,int k){
        if (l==l_&&r==r_) {
            st[v].sum=st[v].sz*k;
            st[v].min=k;
            st[v].max=k;
            st[v].set=true;
            return ;
        }
        push(v);
        int m=(l+r)/2;
        if (r_<=m) {
            set(2*v, l, m, l_, r_, k);
        }
        else if (l_>m){
            set(2*v+1, m+1, r, l_, r_, k);
        }
        else{
            set(2*v, l, m, l_, m, k);
            set(2*v+1, m+1, r, m+1, r_, k);
        }
        combine(st[v], st[2*v], st[2*v+1]);
    }
    
    long long int query(int l,int r){
        return query(1, 0, n-1, l, r).min;
    }
    
    void add(int l, int r, int val){
        add(1, 0, n-1, l, r, val);
    }
    
    void set(int l, int r, int val){
        set(1,0,n-1,l,r,val);
    }
};

int main()
{   ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<array<int,3>> v(n);
    vi temp;
    for(int i=0; i<n; i++){
        cin >> v[i][1] >> v[i][2] >> v[i][0];
        temp.pb(v[i][1]);
        temp.pb(v[i][2]);
    }
    sort(all(v));
    unique(temp);
    for(int i=0; i<n; i++){
        v[i][1] = int(lower_bound(all(temp), v[i][1])-temp.begin()+1);
        v[i][2] = int(lower_bound(all(temp), v[i][2])-temp.begin()+1);
        v[i][1]*=2;
        v[i][2]*=2;
    }
    m = (int)temp.size()*2;
    lazy_segtree T(m+10);
    auto solve = [&](int n){
        vpi a;
        for(int i=0; i<=n; i++){
            a.eb(v[i][2], v[i][1]);
        }
        sort(all(a));
        int last = 2;
        for(int i=0; i<=n; i++){
            if(a[i].se<=last){
                last = max(a[i].fi, last);
            }
        }
        return last==m;
    };
    int ans = 1e6+10;
    int lo = 0 , hi = n-1;
    int st = 0, en = n-1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(solve(mid)){
            en = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    ans = v[en][0]-v[st][0];
    auto add = [&](int l, int r){
        T.add(l, r, 1);
    };
    auto remove = [&](int l, int r){
        auto temp = T.query(l,r);
        if(temp>1){
            T.add(l,r,-1);
            return true;
        }
        return false;
    };
    for(int i=0; i<=en; i++){
        add(v[i][1], v[i][2]);
    }
    while(en<n){
        while(remove(v[st][1],v[st][2])){
            st++;
        }
        ans = min(ans, v[en][0]-v[st][0]);
        en++;
        if(en<n)add(v[en][1], v[en][2]);
    }
    cout << ans << el;
    return 0;
}
