#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
using namespace std;

/* Given an input string S and two characters c1 and c2, you need to replace 
every occurrence of character c1 with character c2 in the given string. */

void replaceCharacter(char input[], char c1, char c2) {
  if(input[0] == '\0')
    return;
  
  if(input[0] == c1) 
    input[0] = c2;
  
  replaceCharacter(input + 1, c1, c2);
}

/*Given a string S, remove consecutive duplicates from it recursively.*/

void removeConsecutiveDuplicates(char *input) {
  if(input[0] == '\0')
    return;
  
  if(input[1] != '\0') {
  	if(input[0] != input[1]) {
      removeConsecutiveDuplicates(input + 1);
    }  
    else {
      int i = 1; 
      for(; input[i] != '\0'; i++) {
        input[i - 1] = input[i];
      }
      input[i - 1] = '\0';
      removeConsecutiveDuplicates(input);
    }
  }
  return;
}

int main() {
	return 0;
}