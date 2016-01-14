#include <queue>
#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#define ii pair <int, int>
#define pii pair <int, ii>
using namespace std;

int main()
{

	int a[100][100];
	int ans[100][100];
	int already[100];

	

	priority_queue  < pair<int, ii>,	vector <pair < int, ii> >, greater <pair < int, ii> > > q;

	int n;
	int m;

	int x;
	int y;
	int w;

	int n1;
	int n2;

	int dist = 0;
	fstream cin;
	cin.open("prims.in", ios::in);

	pair <int, ii> temp;


	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		already[i] = -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = INT_MAX;
			ans[i][j] = INT_MAX;
		}

	}

	for (int i = 0; i <  m; i++) {
		cin >> x;
		cin >> y;
		cin >> w;

		a[x][y] = w;
		a[y][x] = w;
	}
	
	already[0] = 1;

	for (int i = 0; i < n; i++) {
		q.push(pii (a[0][i],(ii ( 0, i))));
	}

	for (int j = 1; j < n; j++) {

		do
		{
			temp = q.top();
			q.pop();
			w = temp.first;
			x = temp.second.first;
			y = temp.second.second;

		} while(already[x] != -1 and already[y] != -1 and !q.empty());
		ans[x][y] = w;
		dist += w;

		if(already[x] == -1) {
			for (int i = 0; i < n; i++) {
				q.push(pii(a[x][i], ii(x, i)));
				already[x] = 1;
			}

		}

		else {
			for (int i = 0; i < n; i++) {
				q.push(pii(a[y][i], ii(y, i)));
				already[y] = 1;
			}

		}


	}

	cout << dist << endl;

	cout << endl << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(ans[i][j] != INT_MAX) {
				cout << ans[i][j]<< " ";
			}

			else {
				cout << "INF"<<" ";
			}

		}

		cout << endl;
	}



}








		

	
