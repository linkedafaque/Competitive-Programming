
/* Problem Statement: Suppose you have a string made up of only 'a' and 'b'. Write a 
recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.

Input: abb
Output: true */

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

bool checkAB(char input[]) {
	if(input[0] != 'a') {
		return false;
	}

	if(input[1] == 'a')
		return checkAB(input + 1);
	else if(input[1] == '\0')
		return true;
	else if(input[1] == 'b' && input[2] == 'b') 
	{
		if(input[3] == '\0')
			return true;
		else 
			return checkAB(input + 3);
	}
	else 
		return false;
}

int main() {
	char input[100];
	cin >> input;
	cout << checkAB(input) << endl;
}
