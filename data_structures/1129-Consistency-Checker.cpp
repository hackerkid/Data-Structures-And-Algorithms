#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	
	int n;
	int t;
	int ok;
	char s[20];
	string x;

	scanf("%d", &t);

	for (int cs = 1; cs <= t; cs++) {
		vector <string> a;
		map <string, bool> mp;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			x = s;
			a.push_back(x);
			mp[x] = true;
		}

		sort(a.begin(), a.end());
		ok = 0;

		for (int i = 0; i < a.size(); i++) {
			string temp;
			for (int j = 0; j < a[i].length() - 1; j++) {
				temp.push_back(a[i][j]);
				if(mp.count(temp)) {
					ok = 1;
				}
			}
		}

		if(!ok) {
			printf("Case %d: YES\n", cs);
		}
		else {
			printf("Case %d: NO\n", cs);
		}

	}

}

