/*
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a 
integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 
13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. 
So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. 
Given a positive number you have to say if its a cube free number and if yes then tell its position among 
cube free numbers.

Input Format:
First line of the test case will be the number of test case T (1 <= T <= 100000) . 
Then T lines follows. On each line you will find a integer number n (1 <= n <= 1000000).

Output Format:
For each input line, print a line containing “Case I: ”, where I is the test case number. 
Then if it is not a cube free number then print “Not Cube Free”. Otherwise print its position 
among the cube free numbers.
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
#define ll unsigned long long int
#define MAX 1000000000
#define MOD 1000000007
using namespace std;

void precomupute(ll *arr, ll n) {
	arr[0] = -1;
	arr[1] = 1;

	for(ll i = 2; i < n; i++) {
		ll cube = i * i * i;
		if(cube < n) {
			arr[cube] = -1;
			for(ll j = cube * 2; j < n; j += cube) {
				arr[j] = -1;
			}
		}
	}

	ll count = 2;
	for(ll i = 2; i < n; i++) {
		if(arr[i] != -1)
			arr[i] = count++;
	}
}

int main() {
	ll arr[1000001], tc;
	cin >> tc;

	precomupute(arr, 1000001);

	for(ll i = 1; i <= tc; i++) {
		ll n;
		cin >> n;

		if(arr[n] == -1) {
			cout << "Case " << i << ": " << "Not Cube Free" << endl;
		}
		else {
			cout << "Case " << i << ": " << arr[n] << endl;
		}
	}
}