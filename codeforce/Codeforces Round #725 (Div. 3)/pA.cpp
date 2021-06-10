//#pragma GCC optimize("O3,unroll-loops")
//#pragma loop_opt(on)
#include<bits/stdc++.h>

//#define Debug
#ifdef Debug
#define io_op
#define debug(x) cerr << "#x " << x << endl;
#else
#define io_op ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x)
#endif

using namespace std;
using pii = pair<int,int>;
using piii = pair<int,pii>;
using ll = long long;
//#define int ll
#define F first
#define S second
#define All(x) x.begin(),x.end()
#define Vi vector<int>
#define Vl vector<ll>
#define Pb push_back
#define Eb emplace_back
#define endl '\n'
#define _ << " " <<

#define coutv(v) for(auto x:v){\
	cout << x << " ";\
}cout << '\n';

constexpr ll mxN = 1e4;
constexpr ll MOD = 1e9+7;

/*
ll pow_mod(int n, int p){
	int rESULt = 1;
	while(p){
		if(p&1) rESULt=(rESULt * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return rESULt;
}
*/

void solver(){
	int n; cin >> n;
	int uidx,lidx;
	int ust=-1,lst=INT_MAX;
	
	for(int i = 0; i<n; i++){
		int tmp;cin>> tmp;
		if(tmp>ust){
			ust = tmp;
			uidx = i;
		}
		if(tmp<lst){
			lst = tmp;
			lidx = i;
		}
	}
//	cout << ust _ lst << endl;
	cout << min({min(uidx,lidx)+n-max(uidx,lidx)+1,max(uidx,lidx)+1,n-min(uidx,lidx)}) << endl;
	
	
}

int main(){
	io_op
	int t;cin >> t;while(t--){ solver(); }
}
