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

int getCodesImpl(string input, string output[10000], int index) {
	if(input.empty())
		return 1;

	int count1 = 0, count2 = 0, i;
	string prefix = "", cur_string = "";
	
	if(input.size() >= 1) {
		cur_string += input[0];
		prefix =  get(cur_string);
		count1 = getCodesImpl(input.substr(1), output, index);
		for(i = index; i < (count1 + index); i++) {
			output[i] = prefix + output[i];
		}
	}

	if(input.size() >= 2) {
		cur_string += input[1];
		if(stoi(cur_string) >= 1 && stoi(cur_string) <= 26) {
			prefix = get(cur_string);
			count2 = getCodesImpl(input.substr(2), output, count1 + index);
			for(; i < (count1 + index + count2); i++) {
				output[i] = prefix + output[i];
			}
		}
	}
	return count1 + count2;
}

int main() {
	string input, output[10000];
	cin >> input;
	int count = getCodesImpl(input, output, 0);
	for(int i = 0; i < count; i++) {
		cout << output[i] << endl;
	}

	return 0;
}	