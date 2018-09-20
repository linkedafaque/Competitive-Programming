
/* Problem Statement: Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are 
given a numeric string S. Write a program to print the list of all possible codes that can 
be generated from the given string.

Input: 1123

Output: 
aabc
kbc
alc
aaw
kw */

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

char get(string character) {
	unordered_map<string, char> input;
	input.clear();

	input["1"] = 'a'; input["2"] = 'b'; input["3"] = 'c';
	input["4"] = 'd'; input["12"] = 'l'; input["20"] = 't';
	input["5"] = 'e'; input["13"] = 'm'; input["21"] = 'u';
	input["6"] = 'f'; input["14"] = 'n'; input["22"] = 'v';
	input["7"] = 'g'; input["15"] = 'o'; input["23"] = 'w';
	input["8"] = 'h'; input["16"] = 'p'; input["24"] = 'x';
	input["9"] = 'i'; input["17"] = 'q'; input["25"] = 'y';
	input["10"] = 'j'; input["18"] = 'r'; input["26"] = 'z';
	input["11"] = 'k'; input["19"] = 's'; 
	return input[character];
}

void printAllPossibleCodesImpl(string input, string output) {
	if(input.size() == 0) {
		cout << output << endl;
		return;
	}

	string tosend = "";
	if(input.size() >= 1) {
		tosend += input[0];
		printAllPossibleCodesImpl(input.substr(1), output + get(tosend));
	}

	if(input.size() >= 2) {
		tosend += input[1];
		if(stoi(tosend) <= 26)
			printAllPossibleCodesImpl(input.substr(2), output + get(tosend));
	}
}

void printAllPossibleCodes(string input) {
	printAllPossibleCodesImpl(input, "");
}

int main() {
	string input;
	cin >> input;
	printAllPossibleCodes(input);
	return 0;
}