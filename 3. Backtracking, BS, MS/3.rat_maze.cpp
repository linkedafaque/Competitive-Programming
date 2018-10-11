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

void print(int maze[][20], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << maze[i][j] << " ";
		}
	}
	cout << endl;
}

void ratInAMazeHelper(int maze[][20], int n, int soln[][20], int i, int j) {
	
	if(i >= n || i < 0) 
		return;

	if(j >= n || j < 0)
		return;

	if(maze[i][j] == 0)
		return;

	if(soln[i][j] == 1)
		return;

	soln[i][j] = 1;

	if(soln[n-1][n-1] == 1) {
		print(soln, n);
		soln[n-1][n-1] = 0;
		return;
	}

	ratInAMazeHelper(maze, n, soln, i - 1, j);
	ratInAMazeHelper(maze, n, soln, i + 1, j);
	ratInAMazeHelper(maze, n, soln, i, j - 1);
	ratInAMazeHelper(maze, n, soln, i, j + 1);
	soln[i][j] = 0;
}

void ratInAMaze(int maze[][20], int n) {
	int soln[1000][20];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			soln[i][j] = 0;
		}
	}
	ratInAMazeHelper(maze, n, soln, 0, 0);
}

int main() {
	int n, maze[10000][20];
	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}
	ratInAMaze(maze, n);
	return 0;
}