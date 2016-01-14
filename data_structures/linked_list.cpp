#include <iostream>
using namespace std;

typedef struct list {
	int item;
	struct list * next;
}list;

list * search(list *l, int x)
{

	if(x == l->item) {
		return l;
	}

	else return search(l->next, x);
}

int main()
{

}

