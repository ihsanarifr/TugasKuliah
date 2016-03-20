#include<iostream>
using namespace std;

struct tree_node
{
    int key;
    tree_node *left, *right;
};

// Binary Search Tree
class BST
{
public:
    tree_node *root;
    BST(){root = NULL;};
    tree_node* newNode(int item);
    tree_node* search(tree_node* node, int key);
    tree_node* insert(tree_node* node, int key);
    tree_node* deleteNode(struct tree_node* root, int key);
    void visit(tree_node* node);
    void preorder(tree_node *node);
    void inorder(tree_node *node);
    void postorder(tree_node *node);
    tree_node * getMinimumNode(tree_node* node);
    tree_node * getMaximumNode(tree_node* node);
    tree_node * getSuccessorNode(tree_node* node);
    tree_node * getPredecessorNode(tree_node* node);
};

// Driver
int main()
{
    /* BST yang akan dibuat
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    // Creating BST
    BST B;

    // Inserting
    B.root = B.insert(B.root, 50);
    B.root = B.insert(B.root, 30);
    B.root = B.insert(B.root, 20);
    B.root = B.insert(B.root, 40);
    B.root = B.insert(B.root, 70);
    B.root = B.insert(B.root, 60);
    B.root = B.insert(B.root, 80);

    // Inorder Traverse
    B.inorder(B.root);

    // Deleting
    B.root = B.deleteNode(B.root, 20);
    cout << "Result" << endl;
    B.inorder(B.root);

    cout << "\nDelete 30\n";
    B.root = B.deleteNode(B.root, 30);
    B.inorder(B.root);

    cout << "\nDelete 50\n";
    B.root = B.deleteNode(B.root, 50);
    B.inorder(B.root);

    // Searching
    tree_node *temp = B.search(B.root, 80);
    if(temp == NULL)
        cout << "\nKEY NOT_FOUND" << endl;
    else
        cout << "\nKEY FOUND: " << temp->key << endl;
    return 0;
}

// Fungsi utilitas untuk membuat node baru
tree_node *BST::newNode(int item){
    tree_node *temp = new(tree_node);
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};

// Pencarian key pada tree
tree_node* BST::search(tree_node* node, int key)
{
    // STUB
}

// Penyisipan key baru pada tree
tree_node* BST::insert(tree_node* node, int key){
    // STUB
};

// Penghapusan key pada tree
tree_node* BST::deleteNode(tree_node* node, int key){
    // STUB
};

// Yang dilakukan ketika node dikunjungi
// Dapat disesuaikan sesuai kebutuhan
void BST::visit(tree_node* node){
    // STUB
}

// Preorder traversal
void BST::preorder(tree_node *node){
    // STUB
};

// Inorder traversal
void BST::inorder(tree_node *node){
    // STUB
};

// Postorder traversal
void BST::postorder(tree_node *node){
    // STUB
};

// Mendapatkan node dengan nilai minimum pada tree
tree_node * BST::getMinimumNode(tree_node* node){
    // STUB
};

// Mendapatkan node dengan nilai maksimum pada tree
tree_node * BST::getMaximumNode(tree_node* node){
    // STUB
};

// Mendapatkan node suksesor
tree_node * BST::getSuccessorNode(tree_node* node){
    // STUB
};

// Mendapatkan node predesesor
tree_node * BST::getPredecessorNode(tree_node* node){
    // STUB
};
