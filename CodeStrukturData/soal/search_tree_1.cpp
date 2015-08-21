#include<iostream>
#include<iomanip>

using namespace std;

struct tree_node{
	int key;
	tree_node *left, *right;
};

class BST
{
public:
	tree_node *root;
	BST(){ root = NULL; };
	//~BST();

	tree_node* newNode(int item);
	tree_node* search(tree_node* node, int key);
	tree_node* insert(tree_node* node, int key);
	tree_node* insert_desc(tree_node* node, int key);
	tree_node* deleteNode(struct  tree_node* root, int key);

	void visit(tree_node* node);
	void preorder(tree_node* node);
	void inorder(tree_node* node);
	void postorder(tree_node* node);
	void inorder_desc(tree_node* node);

	tree_node* getMinimumNode(tree_node* node);
	tree_node* getMaximumNode(tree_node* node);
	tree_node* getSuccessorNode(tree_node* node);
	tree_node* getPredecessor(tree_node* node);
};

// membuat node baru
tree_node* BST::newNode(int item){
	tree_node *temp = new(tree_node);
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// pencarian key pada tree
tree_node* BST::search(tree_node* node, int key){
	// kalo node NULL
	if (node == NULL){
		return node;
	}

	// kalo ketemu
	if (node->key == key)
		return node;

	// kalo key lebih kecil dari node, telususi kiri
	if (key < node->key)
		search(node->left, key);
	else
		//kalo key lebih besar dari node, telusuri kanan
		search(node->right, key);
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

// penyisipan key baru pada tree descending
tree_node* BST::insert_desc(tree_node* node, int key){
	// kalo node kosong
	if (node == NULL)
		return newNode(key);

	// sisip kiri
	if (key > node->key)
		node->left = insert(node->left, key);
	else
		//sisip kanan
		node->right = insert(node->right, key);
	return node;
}

// penghapusan key pada tree
tree_node* BST::deleteNode(struct  tree_node* node, int key){
	//kalo kosong
	if (node == NULL)
		return node;
	if (key < node->key)
		node->right = deleteNode(node->left, key);
	else if (key > node->key)
		node->right = deleteNode(node->right, key);
	else{
		//hanya satu anak
		if (node->left == NULL){
			tree_node * temp = node->right;
			node = NULL;
			return temp;
		}
		else if (node->right == NULL){
			tree_node *temp = node->left;
			node = NULL;
			return temp;
		}
		else{
			// ada dua anak
			tree_node *temp = getSuccessorNode(node);
			node->key = temp->key;

			// hapus suksesor dengan algoritme yang sama
			node->right = deleteNode(node->right, temp->key);
		}
		return node;
	}

}

void BST::visit(tree_node* node){
	cout << node->key << " ";
}

// Preorder transversal
void BST::preorder(tree_node* node){
	// root-kiri-kanan
	if (node != NULL){
		visit(node);
		preorder(node->left);
		preorder(node->right);
	}
}

// Inorder transversal
void BST::inorder(tree_node* node){
	// kiri-root-kanan
	if (node != NULL){
		inorder(node->left);
		visit(node);
		inorder(node->right);
	}
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
// Postorder transversal
void BST::postorder(tree_node* node){
	// kiri-kanan-root
	if (node != NULL){
		postorder(node->left);
		postorder(node->right);
		visit(node);
	}
}

tree_node* BST::getMinimumNode(tree_node* node){
	// mendapatkan ujung paling kiri
	tree_node* current = node;
	while (current->left!=NULL)
	{
		current = current->left;
	}
	return current;
}

tree_node* BST::getMaximumNode(tree_node* node){
	// mendapatkan ujunga paling kanan
	tree_node *current = node;
	while (current->right!=NULL)
	{
		current = current->right;
	}
	return current;
}

tree_node* BST::getSuccessorNode(tree_node* node){
	// mencari paling kecil dari yang terbesar
	// ambil kanan dan kiri terus

	// jika kanan tidak nul maka cari node yang minimum
	if (node->right != NULL)
		return getMinimumNode(node->right);
	else{
		tree_node *ptr = root;

		while (ptr != NULL && node == ptr->right){
			node = ptr;
			ptr = node;
		}
	}
}
tree_node* BST::getPredecessor(tree_node* node){
	// mencaari paling besar dari yang terkecil
	// ambil kiri dan kanan terus

	// jika kiri tidak null maka cari node makksimal
	if (node->left != NULL){
		return getMaximumNode(node->left);
	}
	else{
		tree_node *ptr = root;

		while (ptr != NULL && node == ptr->left){
			node = ptr;
			ptr = node;
		}
	}
}

int main()
{
	BST b;
	/*b.root = b.insert(b.root, 1);
	b.root = b.insert(b.root, 2);
	b.root = b.insert(b.root, 3);
	b.root = b.insert(b.root, 4);
	b.root = b.insert(b.root, 5);
	b.root = b.insert(b.root,6);
	b.root = b.insert(b.root, 7);
	b.root = b.insert(b.root, 8);
	b.root = b.insert(b.root, 9);
	b.root = b.insert(b.root, 10);*/
	int n;
	cin >> n;
	while (n != -1){
		b.root = b.insert(b.root, n);
		cin >> n;
	}

	// deleting
	//b.root = b.deleteNode(b.root, 20);
	//cout << "Terimakaasih";
	// Searching
	/*tree_node *temp = B.search(B.root, 80);
	if (temp == NULL)
		cout << "\nKEY NOT_FOUND" << endl;
	else
		cout << "\nKEY FOUND: " << temp->key << endl;*/

	//b.inorder(b.root);
	b.inorder_desc(b.root);
	//_getch();
	return 0;
}

