#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
using namespace std;


//Find all indexes of a given number
int allIndexesHelper(int input[], int size, int x, int output[], int k, int cur_index) {
  if(size == -1)
    return 0;
  
  if(input[0] == x) {
    output[k++] = cur_index;
  }
  int smallOutput = allIndexesHelper(input + 1, size - 1, x, output, k, cur_index + 1);
  return smallOutput > k ? smallOutput : k;
}


//Find the last index of the number in the array
int lastIndex(int input[], int size, int x) {
  if(size == 0)
    return -1;
  
  int smallOutput = lastIndex(input + 1, size - 1, x);
  
  if(smallOutput != -1) {
    return 1 + smallOutput;
  }
  if(input[0] == x) {
    smallOutput = 0;
    return smallOutput;
  }
  else {
    return smallOutput;
  }
}



//Find the first index of the number in the array
int firstIndex(int input[], int size, int x) {
  if(size == 0)
    return -1;
  
  if(input[0] == x)
    return 0;
  
  int smallOutput = firstIndex(input + 1, size - 1, x);
  
  if(smallOutput != -1)
    return 1 + smallOutput;
  else 
    return smallOutput;
}



//Check if a number exists in an array
bool checkNumber(int input[], int size, int x) {
  if(size == 1)
    return input[0] == x;
  
  if(input[0] == x)
    return true;
  return checkNumber(input + 1, size - 1, x);
}


//Sum of all numbers in an array
int sum(int input[], int n) {
  if(n == 1)
    return input[0];
  
  int smallSum = sum(input + 1, n - 1);
  return input[0] + smallSum;
}


//Check if array is sorted
bool is_sorted(int arr[], int size) {
	if(size == 0 || size == 1)
		return true;

	if(arr[0] > arr[1]) {
		return false;
	}
	bool isSmallerSorted = is_sorted(arr + 1, size - 1);
	return isSmallerSorted;
}


int main() {

	int arr[] = {1, 2, 10, 4, 5};
	cout << is_sorted(arr, 5) << endl;
	return 0;
}