/*
Problem Statement : Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of 
candies (between 1 and 1000000000). Shakey want to distibute these candies among his K (1<=K<=1000000000)
 IIIT-Delhi students. He want to distibute them in a way such that:

1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.

As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in 
finding out what is the maximum number of candies which a student can get.

Input: 
2
3 2 
3 1 4
4 1
3 2 3 9

Output:
3
9
*/


#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<math.h>
#include<unordered_map>
#include<algorithm>
#include<climits>
#define ll long long int
#define MAX 1000000000
using namespace std;

bool isPossible(ll candies, ll arr[], ll total, ll n) {
  for(ll i = 0; i < n; i++) {
    total -= (arr[i] / candies);
  }
  if(total <= 0) 
    return true;
  return false;
}

int main() {
  ll tc, arr[50001];
  cin >> tc;
  
  while(tc--) {
    ll n, k;
    cin >> n >> k;
    
    for(ll i = 0; i < n; i++) {
      cin >> arr[i];
    }
    
    ll start = 1, end = MAX, maxm = LLONG_MIN;
    while(start <= end) {
      ll mid = (start + end) / 2;
      if(isPossible(mid, arr, k, n)) {
        maxm = maxm < mid ? mid : maxm;
        start = mid + 1;
      }
      else {
        end = mid - 1;
      }
    }
    maxm = maxm == LLONG_MIN ? 0 : maxm;
    cout << maxm << endl;
  }
}