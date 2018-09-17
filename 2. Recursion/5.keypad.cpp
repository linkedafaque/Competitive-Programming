#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
using namespace std;

/* Given an integer n, using phone keypad find out all the possible strings that 
can be made using digits of input n. Return empty string for numbers 0 and 1. */

string h(int num) 
{
  unordered_map<int, string> m;
  m.clear();
  m[0] = "";
  m[1] = "";
  m[2] = "abc";
  m[3] = "def";
  m[4] = "ghi";
  m[5] = "jkl";
  m[6] = "mno";
  m[7] = "pqrs";
  m[8] = "tuv";
  m[9] = "wxyz";
  return m[num];
}

int keypad(int num, string output[]) {
  if(num == 0) {
    output[0] = "";
    return 1;
  }
  
  int smallOutput = keypad(num / 10, output);
  int stringSize = h(num % 10).size();
  int total = smallOutput * (stringSize - 1);

  for(int i = smallOutput; i < (total + smallOutput); i++) {
    output[i] = output[i - smallOutput];
  }

  total = smallOutput * stringSize;
  int index = 0;
  for(int i = 1; i <= total; i++)
  {
    output[i -1] = output[i - 1] + h(num % 10)[index];
    if(i % smallOutput == 0)
      index++;
  }
  return total;
}

int main() {
  int input;
  cin >> input;

  string output[1000];
  int count = keypad(input, output);

  for(int i = 0; i < count; i++) {
    cout << output[i] << endl;
  }
}