#include <iostream>
#include <list>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

	double a[1000];
	int n;
	double x;
	double maxi;
	maxi = -1.0;


	cout << "Enter the number of elements\n";
	cin >> n;
	vector <list <double> > b(n+1);

	for (int i = 0; i < n; i++) {
		
		cin >> x;
		a[i] = x;

		maxi = max(x, maxi);

	}
	
	maxi++;

	for (int i = 0; i < n; i++) {
		a[i] = a[i] / maxi;
	}

	

	for (int i = 0; i < n; i++) {
		b[n * a[i]].push_back(a[i]);
	}

	for (int i = 0; i < n; i++) {
		b[i].sort();
	}
	
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (list <double>::iterator x = b[i].begin(); x != b[i].end(); x++) {
			cout << *x * maxi<<" ";
			cout << endl;
		}

	}

}

