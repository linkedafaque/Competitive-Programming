#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
using namespace std;

int factorial(int n) {
	if(n == 0)
		return 1;
	int smallOutput = factorial(n-1);
	return n * smallOutput;
}

int main() {
	int n;
	cin >> n;

	int output = factorial(n);
	cout << output << endl;

	return 0;
}