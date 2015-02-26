#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;
vector <pair <int, int> > a;
double bruteforce(int l, int r, vector <pair<int, int> > a)
{
	double sum = 10000000000;
	double temp;
	int x1;
	int y1;
	int x2;
	int y2;


	for (int i = l; i <= r; i++) {
		for (int j = i + 1; j <= r; j++) {
			x1 = a[i].first;
			y1 = a[i].second;
			x2 = a[j].first;
			y2 = a[j].second;

			temp = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
			if(temp < sum) {
				sum = temp;
			}

		}

	}


	return sum;
}


double wow(int l, int r)
{
	double d1;
	double d2;
	double d;
	double dd;
	int n;
	int t;

	if(r - l + 1 <= 3) {
		dd = bruteforce(l, r, a);
	}

	else {
		n = (l + r) / 2;
		d1 = wow(l, n);
		d2 = wow(n + 1, r);
		d = min(d1, d2);
		vector < pair <int, int> > temp;
		
		for (int i = l; i <= r; i++) {
			if(abs(a[n].first - a[i].first) <= d) {
					temp.push_back(a[i]);
			}

		}

		dd = bruteforce(0, temp.size() - 1, temp);
		dd = min(dd, d);

	}

	return dd;




}

int main()
{
	int n;
	pair <int, int> x;
	cin >> n;

	for (int i = 0; i < n ;i++) {
		cin >> x.first;
		cin >> x.second;
		a.push_back(x);
	}

	sort(a.begin(), a.end());
	cout << wow(0, n-1) << endl;

}



