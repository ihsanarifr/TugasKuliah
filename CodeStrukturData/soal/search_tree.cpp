#include<iostream>
#include<iomanip>
using namespace std;

struct tree_node{
    int key;
    tree_node *right,*left;
};
class BST
{
public:
	tree_node *root;
	BST(){ root = NULL; };

	tree_node* newNode(int item);
	tree_node* insert(tree_node* node, int key);

	void visit(tree_node* node);
	void inorder_desc(tree_node* node);
};

// membuat node baru
tree_node* BST::newNode(int item){
	tree_node *temp = new(tree_node);
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// penyisipan key baru pada tree
tree_node* BST::insert(tree_node* node, int key){
	// kalo node kosong
	if (node == NULL)
		return newNode(key);

	// sisip kiri
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		//sisip kanan
		node->right = insert(node->right, key);
	return node;
}

void BST::visit(tree_node* node){
	cout << node->key << " ";
}

// Inorder_desc transversal
void BST::inorder_desc(tree_node* node){
	// kanan-root-kiri
	if (node != NULL){
		inorder_desc(node->right);
		visit(node);
		inorder_desc(node->left);
	}
}

int main()
{
	BST b;
	/*
	b.root = b.insert(b.root, 1);
	b.root = b.insert(b.root, 2);
	b.root = b.insert(b.root, 3);
	b.root = b.insert(b.root, 4);
	b.root = b.insert(b.root, 5);
	b.root = b.insert(b.root,6);
	b.root = b.insert(b.root, 7);
	b.root = b.insert(b.root, 8);
	b.root = b.insert(b.root, 9);
	b.root = b.insert(b.root, 10);*/
	//int n[10]={1,2,3,4,5,6,7,8,9,10};
	int n;
	cin >> n;
	while (n != -1){
        //for(int i;i<10;i++)
		b.root = b.insert(b.root, n);
		cin >> n;
	}

	//b.inorder(b.root);
	b.inorder_desc(b.root);
	return 0;
}

