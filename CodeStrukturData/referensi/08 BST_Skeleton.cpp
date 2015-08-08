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
/*
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
*/
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
    // kalo node NULL
    if(node == NULL)
        return node;
    // kalo ketemu
    if(node->key == key)
        return node;
    // kalo key lebih kecil dari node, telusuri kiri
    if(key<node->key)
        search(node->left,key);
    else
    // kalo key lebih besar dari node, telusuri kanan
        search(node->right,key);
}

// Penyisipan key baru pada tree
tree_node* BST::insert(tree_node* node, int key){
    // STUB
    if(node ==NULL)
        return newNode(key);
    //sisip kiri
    if(key < node->key)
        node->left = insert(node->left,key);
    else
        //sisip kanan
        node->right = insert(node->right,key);
    return node;
};

// Penghapusan key pada tree
tree_node* BST::deleteNode(tree_node* node, int key){
    // STUB
    if(node == NULL)
        return node;
    if(key < node->key)
        node->left = deleteNode(node->left,key);
    else if(key>node->key)
        node->right = deleteNode(node->right,key);
    else{
        //hanya satu anak
        if(node->left==NULL){
            tree_node *temp = node->right;
            node = NULL;
            return temp;
        }else if(node->right==NULL){
            tree_node *temp = node->left;
            node = NULL;
            return temp;
        }else{
            //ada dua anak
            tree_node *temp = getSuccessorNode(node);
            node->key = temp->key;

            // hapus suksesor dengan algoritme yang sama
            node->right = deleteNode(node->right,temp->key);
        }
        return node;
    }

};

// Yang dilakukan ketika node dikunjungi
// Dapat disesuaikan sesuai kebutuhan
void BST::visit(tree_node* node){
    // STUB
    cout << node->key << " ";
}

// Preorder traversal
void BST::preorder(tree_node *node){
    // root-kiri-kanan
    if(node != NULL){
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
};

// Inorder traversal
void BST::inorder(tree_node *node){
    // kiri-root-kanan
    if(node !=NULL){
        inorder(node->left);
        visit(node);
        inorder(node->right);
    }
};

// Postorder traversal
void BST::postorder(tree_node *node){
    // kiri-kanan-root
    if(node !=NULL){
        postorder(node->left);
        postorder(node->right);
        visit(node);
    }
};

// Mendapatkan node dengan nilai minimum pada tree
tree_node * BST::getMinimumNode(tree_node* node){
    // mendapatkan node ujung kiri
    tree_node *current = node;
    while(current->left!=NULL){
        current = current->left;
    }
    return current;
};

// Mendapatkan node dengan nilai maksimum pada tree
tree_node * BST::getMaximumNode(tree_node* node){
    // mendapatkan node ujung kanan
    tree_node *current = node;
    while(current->right != NULL){
        current = current->right;
    }
    return current;
};

// Mendapatkan node suksesor
tree_node * BST::getSuccessorNode(tree_node* node){
    // mencari paling kecil dari yang terbesar
    // ambil kanan dan terus ke kiri.

    // jika kanan tidak null maka cari node yg minimum.
    if(node->right != NULL)
        return getMinimumNode(node->right);
    else{
        tree_node *ptr = root;

        while(ptr != NULL && node == ptr->right){
            node = ptr;
            ptr = node;
        }
    }
};

// Mendapatkan node predesesor
tree_node * BST::getPredecessorNode(tree_node* node){
    return getMaximumNode(node->left);
};
