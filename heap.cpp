#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;
// plot "result.dat" using 1:2 with lines

struct node {
    struct node * parent;
    struct node * right;
    struct node * left;
    int val;
};

int toBinary(bool binary[32], int count)
{
    int i = 0;

    while(count) {
        binary[i] = count % 2;
        count /= 2;
        i++;
    }



    return i;

}


int heapify(struct node * temp)
{
    while(temp->val > temp->parent->val) {
        swap(temp->val, temp->parent->val);
        temp = temp->parent;
    }
}

//get the parent of the required node
struct node * findGuy(struct node * temp, int n, bool binary[32]) 
{
        for (int i = n-2; i > 0 ; i--) {
            if(binary[i]) {
                temp = temp->right;
            }

            else {
                temp = temp->left;
            }

        }
        
        return temp;
}

//construct heap by taking data one by one by inserting at last position

struct node * buildHeap(struct node * root, int data, int count) 
{
    
    bool binary[32];
    struct node * temp;

    int n;
    int i;

    if(root == NULL) {
        count++;
        root = new node();
        root->left = NULL;
        root->right = NULL;
        root->val = data;
        root->parent = root;
    } 
    
    else {
        temp = root;
        n = toBinary(binary, count+1);
        count++;
        temp = findGuy(root, n, binary) ;

        if(binary[0]) {
            temp->right = new node();
            temp->right->val = data;
            temp->right->parent = temp;
            temp->right->left = NULL;
            temp->right->right = NULL;

            heapify(temp->right);
        }

        else {
            
            temp->left = new node();
            temp->left->val = data;
            temp->left->parent = temp;
            temp->left->left = NULL;
            temp->left->right = NULL;

            heapify(temp->left);
        }

    }

    return root;

}

//pre order
int display(struct node * temp)
{
    if(temp == NULL)
        return 0;

    cout << temp->val<<endl;
    display(temp->left);
    display(temp->right);
}

void downHeapify(struct node * root)
{
	struct node * next;
	int greatest;
	next = root;
	greatest = root->val;

	if(root == NULL) {
		return;
	}

	if(root->left != NULL and greatest < root->left->val) {
		greatest = root->left->val;
		next = root->left;
	}

	if(root->right != NULL and root->right->val > greatest) {
		greatest = root->right->val;
		next = root->right;
	}

	

	if(greatest != root->val) {
		//cout <<"heapify going on "<<root->val<<" "<<greatest<<endl;
		swap(root->val, next->val);
		downHeapify(next);
	}

}

struct node * deleteRoot(struct node * root, int count) 
{   
   	if(root == NULL) {
		cout << "Empty tree\n";
	}
	struct node * temp;
    struct node * child;
    bool binary[32];
    int n = toBinary(binary, count); //returns the binary rep in reversed order
    temp = findGuy(root,n, binary);

	if(count == 1) {
		delete root;
		root = NULL;
		return root;
	}

	if(count % 2 == 0) {
		child = temp->left;
		//cout << "child root swapping ";
		//cout << child->val << " "<<root->val<<endl;
		swap(child->val, root->val);
		temp->left = NULL;
		
		delete child;
		downHeapify(root);

	}

	else {
			child = temp->right;
			//cout << "child root swapping ";
			//cout << child->val << " "<<root->val<<endl;
			swap(child->val, root->val);
			temp->right = NULL;
			delete child;
			downHeapify(root);
	}

	return root;


}



int main()
{
    struct node * root;
    int n;
    int count;
    int x;
	int f;
	int a[] = {2, 3, 6,1, 5, 11, 7};
	int ans[100];
	srand(time(NULL));
	fstream pout;
	pout.open("result.dat", ios::out);

    cout << "Enter the number of elements to be inserted" << endl;
   
	for (int k = 0; k < 20; k++) {

	n = rand() % 500;
	n = n * 300;

   
	clock_t tStart = clock();
	
	root = NULL;
    count = 0;
    
	for(int i = 0; i < n; i++) {
		f = rand() % 500;
        root = buildHeap(root, f, i);
    }

    count = n;
	while(count) {
//		cout << root->val<<" ";
		deleteRoot(root, count);
		count--;
	}
	double p;
	p =  (double)(clock() - tStart);
	pout <<n <<" "<< p << endl;

	}


}

