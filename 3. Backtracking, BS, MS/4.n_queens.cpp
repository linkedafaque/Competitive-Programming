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

int board[11][11];

void init(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			board[i][j] = 0;
		}
	}
}

void printBoard(int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
	}
	cout << endl;
}

bool isPossible(int row, int col, int n) {
	int i = row, j = col;
	while(i >=0 && j >= 0) {
		if(board[i--][j--] == 1)
			return false;
	}

	i = row; j = col;
	while(i >= 0 && j < n) {
		if(board[i--][j++] == 1)
			return false;
	}	

	i = row; j = col;
	while(i >= 0) {
		if(board[i--][j] == 1)
			return false;
	}
	return true;
}

void placeNQueensHelper(int n, int row) {
	if(row >= n) {
		printBoard(n);
		return;
	}

	for(int col = 0; col < n; col++) {
		if(isPossible(row, col, n)) {
			board[row][col] = 1;
			placeNQueensHelper(n, row + 1);
			board[row][col] = 0;
		}
	}
}

void placeNQueens(int n) {
	placeNQueensHelper(n, 0);
}

int main() {
	int n;
	cin >> n;
	init(n);
	placeNQueens(n);
	return 0;
}