#include<iostream>
using namespace std;

int main() {
	int i = 500;

	//prints address of i
	cout << &i << endl;

	//pointer: want some variable which can store &i
	int *p = &i;
	cout << p << endl;

	//get the data pointed by p: dereference operator
	cout << *p << endl;

	//size of pointer p, differs from machine to machine
	cout << sizeof(p) << endl;

	double a = 12.2;
	double *dp = &a;

	cout << &a << endl << dp << endl;
}