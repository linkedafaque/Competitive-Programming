#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<algorithm>
using namespace std;

struct Interval {
	int start_time;
	int end_time;
};

bool compare(Interval i1, Interval i2) {
	return i1.start_time < i2.start_time;
}

int main() {

	//Sorting an array
	//Use greater<int>() for reverse sort
	int arr[] = { 4, 1, 2, 6, 3, 5 };
	sort(arr, arr+6);
	for(int i = 0; i < 6; i++) {
		cout << arr[i] << " " << endl;
	}
	cout << endl;

	//Sorting based on a parameter
	Interval interval[] = {
		{ 6,4 },
		{ 3,4 },
		{ 4,6 },
		{ 8,13 }
	};
	sort(interval, interval+4, compare);

	for(int i = 0; i < 4; i++) {
		cout << interval[i].start_time << ":" << interval[i].end_time << endl;
	}
	cout << endl;


	//Binary Search
	cout << binary_search(arr,arr+6,8) << endl;

	//lower_bound returns the index of the asked element or just higher than asked element
	//returns the first index if the asked element is repeated
	cout << lower_bound(arr,arr+6,3) - arr << endl;

	//Gives index of just next higher number
	cout << upper_bound(arr,arr+6,3) - arr << endl;

	return 0;
}
