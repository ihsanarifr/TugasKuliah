//tree_node* AVL::deleteNode(tree_node* node, int key){
#include<iostream>
using namespace std;

struct tree_node
{
    int key;
    tree_node *left, *right;
    int height;
};

// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}

// Binary Search Tree
class AVL
{
public:
    tree_node *root;
    AVL(){root = NULL;};
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
    int height(tree_node* node);
    int getBalance(tree_node *N);
    tree_node* leftRotate(tree_node *x);
    tree_node* rightRotate(tree_node *y);
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
    AVL B;

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
tree_node *AVL::newNode(int item){
    tree_node *temp = new(tree_node);
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
};

// Pencarian key pada tree
tree_node* AVL::search(tree_node* node, int key)
{
    if(node == NULL) return node;
    if(node->key == key) return node;
    if(key < node->key)
        search(node->left, key);
    else
        search(node->right, key);
}

// Penyisipan key baru pada tree
tree_node* AVL::insert(tree_node* node, int key){
    if(node==NULL)
        return(newNode(key));
    if(key< node->key)
        node->left = insert(node->left,key);
    else
        node->right = insert(node->right,key);

    // update tinggi
    node->height = max(height(node->left),height(node->right))+1;

    int balance = getBalance(node);

    // kasus 1: left left case
    if(balance > 1 && key < node->left->key)
        return rightRotate(node);

    // kasus 4: right right case
    if(balance < -1 && key > node->right->key)
        return leftRotate(node);

    // kasus 2: left right case
    if(balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // kasus 3: right left case
    if(balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
};

// Penghapusan key pada tree
tree_node* AVL::deleteNode(tree_node* node, int key){
    if(node==NULL)
        return node;
    if(key < node->key)
        node->left = deleteNode(node->left,key);
    else if(key > node->right){
        node->right = deleteNode(node->right,key);
    }else{
        //kondisi 1 & 2
        if((node->left=NULL) || (node->right==NULL)){
            tree_node *temp = node->left ? node->left : node->right;// If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    //  this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

            //kondisi 1
            if(temp==NULL){
                temp=node;
                node=NULL;
            }else{
                *node = *temp;
                temp=NULL;
            }
        }else{
            // kondisi 3
            node *temp = getPredecessorNode(node->right);

            node->key=temp->key;
            node->right = deleteNode(node->right,temp->key);
        }
    }

    // balancing
    // jika tree hanya satu node
    if (node == NULL)
      return node;

    // STEP 2: update ketinggian
    node->height = max(height(node->left), height(node->right)) + 1;

    // STEP 3: dapat nilai ketinggian
    int balance = getBalance(node);

    // Jika tree tidak balance maka nanti akan dilakukan 4 kemungkinan rotasi

    // kiri kiri
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // kiri kanan
    if (balance > 1 && getBalance(node->left) < 0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // kanan kanan
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // kanan kiri
    if (balance < -1 && getBalance(node->right) > 0)
    {
        root->right = rightRotate(node->right);
        return leftRotate(root);
    }

    return root;
};

// Yang dilakukan ketika node dikunjungi
// Dapat disesuaikan sesuai kebutuhan
void AVL::visit(tree_node* node){
    cout << node->key << " ";
}

// Preorder traversal
void AVL::preorder(tree_node *node){
    if (node != NULL)
    {
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
};

// Inorder traversal
void AVL::inorder(tree_node *node){
    if (node != NULL)
    {
        inorder(node->left);
        visit(node);
        inorder(node->right);
    }
};

// Postorder traversal
void AVL::postorder(tree_node *node){
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        visit(node);
    }
};

// Mendapatkan node dengan nilai minimum pada tree
tree_node * AVL::getMinimumNode(tree_node* node){
    tree_node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
};

// Mendapatkan node dengan nilai maksimum pada tree
tree_node * AVL::getMaximumNode(tree_node* node){
    tree_node* current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
};

// Mendapatkan node suksesor
tree_node * AVL::getSuccessorNode(tree_node* node){
    return getMinimumNode(node->right);
};

// Mendapatkan node predesesor
tree_node * AVL::getPredecessorNode(tree_node* node){
    return getMaximumNode(node->left);
};

/* Right Rotation

                y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3
*/
tree_node* AVL::rightRotate(tree_node *y)
{
    tree_node *x = y->left;
    tree_node *T2= x->right;

    //rotasi
    x->right = y;
    y->left = T2;

    // update tinggi
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

    return x;
}

/* Left Rotation

                y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3
*/
tree_node* AVL::leftRotate(tree_node *x)
{
    tree_node *y = x->left;
    tree_node *T2= y->right;

    //rotasi
    y->right = x;
    x->left = T2;

    // update tinggi
    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(x->right))+1;

    return y;
}

// Mengecek keseimbangan pada node N
int AVL::getBalance(tree_node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Mengakses nilai tinggi pada node
int AVL::height(tree_node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

//};
