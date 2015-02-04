#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
using namespace std;
int count;
struct node {

    struct node * left;
    struct node * right;
    int data;
};

/*
struct node *search(int val, struct node * root) 
{
    struct node * parent;
    struct node * temp2;
    
    parent = root;
    
	if(val < parent->data && parent->left != NULL) {
        return search(val, parent->left);
    } 
	
	else if(val < parent->data && parent->left == NULL) {
    
        return parent;
    } 
	
	else if(val > parent->data and parent->right !=NULL) {
        return search(val, parent->right);
    } 
	
	
	else {
        return parent;
    }
}

*/

struct node * searchParent(int val, struct node * root) 
{
   if(root->data < val and root->right == NULL)
	   return root;

   if(root->data > val and root->left == NULL)
	   return root;

   if(root->data < val)
	   return searchParent(val, root->right);

   return searchParent(val, root->left);

}

struct node * search(int val, struct node * root) 
{
	
  
   if(root->data > val and root->left->data == val) {
	   return root;
   }

   if(root->data < val and root->right->data == val) {
	   return root;
   }

   if(root->data > val) {
	   return search(val, root->left);
   }

   if(root->data < val) {
	   return search(val, root->right);
   }


}







int findSucc(struct node * guy)
{
	if(guy->left == NULL)
		return guy->data;

	return findSucc(guy->left);

}
void deleteNode(int x, struct node * root )
{

	struct node * parent;
	struct node * child;
	bool left;
	parent = search( x, root);
	if(parent->data < x) {
		child = parent->right;
		left = 0;

	}

	else {
		child = parent->left;
		left = 1;
	}

	if((child->right == NULL) and (child->left == NULL)) {

		if(left) {
			parent->left = NULL;
		}

		else {
			parent->right = NULL;
			
		}

		return;

	}



	if(child->right == NULL) {
		if(left) {
			parent->left = child->left;
		}

		else {
			parent->right = child->left;
		}

		return;

	}

	else {
		if(child->left == NULL) {
			if(left) {
				parent->left = child->right;
			}

			else {
				parent->right = child->right;
			}

		}

	}
	int succ;
	cout << "here";
	struct node * succParent;
	
	if(child->left != NULL and child->right != NULL) {
		succ = findSucc(child->right);
		cout << succ << "succ\n";
		succParent = search(succ, root);
		cout << succParent->data<<"parent of succ\n";
		cout << child->data<<"child data\n";
		child->data = succ;
		if(succParent->data > succ) {
			succParent->left->data = succ-1;
		}

		else {
			succParent->right->data = succ+1;
		}

		deleteNode(succ+1, root);

		
		

	}

}




struct node * create(int val, struct node * root)
{

    struct node * temp;
    if(root == NULL) {
        root = new struct node();
        root->data = val;
        root->left = NULL;
        root->right = NULL;
        count++;    
        return root;
    }

    temp = searchParent(val, root);
    if(temp->data < val) {
        temp->right = new struct node();
        temp->right->data = val;
        temp->right->left = NULL;
        temp->right->right = NULL;
   
        return root;
    }
	
	else {
        temp->left = new struct node();
        temp->left->data = val;
        temp->left->left = NULL;
        temp->left->right = NULL;
        return root;
    }
    
}
    

void display(struct node * root)
{

    if(root == NULL) {
        return;
    }

    else {
        cout << root->data<<endl;
        display(root->left);
        display(root->right);
    }


}





int main()
{

    

    struct node * root;
    fstream fcout;
    fcout.open("av.dat", ios::out);
    root = NULL;    
    srand (time (NULL));
    int a[] = {2, 5, 8, 1, 3, 9, 10};
    int x;
    int n;
	n = 7;
    root = NULL;    
    count = 0;
    for (int i =0; i < n; i++) {
        x = rand() % 100;

        root = create(a[i], root);
    }

	display(root);
	deleteNode(5, root);
	cout << endl;
	cout << endl;
	
	display(root);



}



