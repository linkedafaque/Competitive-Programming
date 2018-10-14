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

class Triplet {
public:
	int gcd;
	int x;
	int y;
};

Triplet extended_euclid(int a, int b) {

	Triplet ans;
	if(b == 0) {
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}

	Triplet smallAns = extended_euclid(b, a % b);
	
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x - ((a/b) * smallAns.y);
	return ans;
}

int main() {
	int a, b, tc;
	cin >> tc;

	while(tc--) {
		cin >> a >> b;
		Triplet ans = extended_euclid(a, b);
		cout << "gcd: " << ans.gcd << " x: " << ans.x << " y: " << ans.y << endl;
	}
}