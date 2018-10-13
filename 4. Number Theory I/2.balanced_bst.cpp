/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count 
of possible binary trees which are balanced. This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.

Input: 3
Output: 15

Input: 4
Output: 315
*/

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
#include<algorithm>
#include<climits>
#define ll long long int
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

ll balancedBTs(ll h) {
	if(h == 0 || h == 1)
		return 1;
	
	ll h_1 = balancedBTs(h - 1) % MOD;
	ll h_2 = (2 * (balancedBTs(h - 2) % MOD)) % MOD;
	ll ans = (h_1 * ((h_2 + h_1) % MOD)) % MOD;
	return ans;
}

int main() {
	int h;
	cin >> h;
	cout << balancedBTs(h) << endl;
}