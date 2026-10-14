#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
#ifdef LOCAL
#define debug(x) cout << #x << " is " << x << endl;
#define debugVec(x) cout << #x << ": "; for(auto moo : x) cout << moo << ' '; cout << endl;
#define debug2d(x) cout << #x << ":\n"; for(auto moo : x){for(auto mooo : moo) cout << mooo << ' ';cout << endl;}
#else
#define debug(x)
#define debugVec(x)
#define debug2d(x)
#endif

void print128(ll n){
	if(n){
		print128(n/10);
		cout << int(n % 10);
	}
}

int main(){
	int n1;
	cin >> n1;
	ll n = n1;
	auto start = chrono::high_resolution_clock::now();
	vector<vector<ll>> table(n+1, vector<ll>(n+1,0));
	table[1][1] = 1;
	for(ll i = 2; i <= n; ++i){
		for(ll j = 1; j <= i; ++j){
			table[i][j] = table[i-1][j-1] + table[i-j][j];
		}
	}
	auto end = chrono::high_resolution_clock::now();
	for(ll i = 1; i <= n; ++i){
		ll sum = 0;
		for(ll j = 1; j <= i; ++j){
			sum += table[i][j];
		}
		print128(sum);
		cout << ' ';
	}
	auto time = chrono::duration_cast<chrono::microseconds>(end - start);
	cout << "\nTime: " << time.count() << " microseconds" << endl;
}
