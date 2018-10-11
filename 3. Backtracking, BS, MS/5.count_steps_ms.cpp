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
using namespace std;

ll merge(ll arr[], ll si, ll mid, ll ei) {
  ll i = si, j = mid + 1, temp[ei - si + 1], k = 0, total_sum = 0;
  
  while(i <= mid && j <= ei) {
    if(arr[i] <= arr[j]) {
      total_sum += arr[i] * (ei - j + 1);
      temp[k++] = arr[i++];
    }
    else if(arr[i] > arr[j]) {
      temp[k++] = arr[j++];
    }
  }
  
  while(i <= mid) {
    temp[k++] = arr[i++];
  }
  
  while(j <= ei) {
    temp[k++] = arr[j++];
  }
  
  k = 0;
  for(ll i = si; i <= ei; i++) {
    arr[i] = temp[k++];
  }
  return total_sum;
}

ll sumHelper(ll arr[], ll si, ll ei) {
  if(si >= ei) {
    return 0;
  }
  
  ll mid = (si + ei) / 2;
  ll left = sumHelper(arr, si, mid);
  ll right = sumHelper(arr, mid + 1, ei);
  return (left + right + merge(arr, si, mid, ei));
}

ll getsum(ll arr[], ll n) {
  return sumHelper(arr, 0, n);
}

int main() {
  ll tc, arr[100000];
  cin >> tc;
  
  while(tc--) {
    ll n;
    cin >> n;
   	for(int i = 0; i < n; i++) {
        cin >> arr[i];
      }
      
      ll sum = getsum(arr, n - 1);
      cout << sum << endl;
    }
}