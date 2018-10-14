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

int euclid_gcd(int a, int b) {
	if(a < b)
		return euclid_gcd(b, a);
	
	if(b == 0)
		return a;
	
	return euclid_gcd(b, a % b);
}

int main() {
	int a, b; 
	cin >> a >> b;
	cout << euclid_gcd(a, b) << endl;
}