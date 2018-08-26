#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
using namespace std;

int main() {

	//Vector: Dynamic Array
	//Initializes an array 'v' with 5 elements (0)
	vector<int> v(5);

	for(int i = 0; i < v.size(); i++) {
		v[i] = i+1;
	}

	//Pointer to an element in the array
	vector<int>::iterator it;

	//Traversing the entire array with an iterator(pointer)
	for(it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}


	//Strings
	string s = "afaque";
	string s1(s,1,4);
	cout << s << " " << s1 << endl;

	//Starting from index 1, give next 4 characters
	string s2 = s.substr(1,4);
	cout << s2 << endl;

	if(s1.compare(s2) == 0) 
		cout << "s1 & s2 is same" << endl;
	else
		cout << "s1 & s2 are not same" << endl;


	//Pair
	pair<int, char> p1;
	pair<int, char> p2(2, 'a');

	p1 = make_pair(1, 'b');
	cout << p1.first << " " << p1.second << endl;
	cout << p2.first << " " << p2.second << endl;


	//Set
	set<int> set1;
	set<int>::iterator set_it;
	int arr[] = {1,1,2,2,3,3,3,4,5,5};

	for(int i = 0; i < 10; i++) {
		set1.insert(arr[i]);
	}

	for(set_it = set1.begin(); set_it != set1.end(); set_it++) {
		cout << *set_it << endl;
	}

	if(set1.find(7) == set1.end())
		cout << "Element missing" << endl;
	else
		cout << "Element found!" << endl;
 
	return 0;
}