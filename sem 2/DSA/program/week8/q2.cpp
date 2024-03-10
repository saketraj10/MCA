#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        left = right = NULL;
    }
};
class BinarySearchTree{
    private:
    TreeNode* root;
    public:
    BinarySearchTree(){
        root = NULL;
    }

    void insert(int val){
        root = insertHelper(root,val);
    }

    TreeNode* insertHelper(TreeNode* node, int val){
        if(node==NULL){
            return new TreeNode(val);
        }

        if(val < node->val){
            node->left = insertHelper(node->left, val);
        }
        else if(val > node->val){
            node->right = insertHelper(node->right, val);
        }
        return node;
    }
    void preorderTraversal(){
        preorderTraversal(root);
        cout<<endl;
    }

    void preorderTraversal(TreeNode* node){
        if(node != NULL){
            cout<<node->val<<" ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    void inorderTraversal(){
        inorderTraversal(root);
        cout<<endl;
    }

    void inorderTraversal(TreeNode* node){
        if(node != NULL){
            inorderTraversal(node->left);
            cout<<node->val<<" ";
            inorderTraversal(node->right);
        }
    }

    void postorderTraversal(){
        postorderTraversal(root);
        cout<<endl;
    }
    void postorderTraversal(TreeNode* node){
        if(node != NULL){
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout<<node->val<<" ";
        }
    }
};
int main(){
    BinarySearchTree bst;
    int ch;
    do{
        cout<<"1. Insert into Binary Search Tree"<<endl;
        cout<<"2. Preorder Traversal"<<endl;
        cout<<"3. Inorder Traversal"<<endl;
        cout<<"4. Postorder Traversal"<<endl;
        cout<<"Enter your choice, 0 to stop: ";
        cin>>ch;
        switch(ch){
            case 1:
                int val;
                cout<<"enter the value to insert: ";
                cin>>val;
                bst.insert(val);
                break;
            case 2:
                bst.preorderTraversal();
                break;
            case 3: 
                bst.inorderTraversal();
                break;
            case 4:
                bst.postorderTraversal();
                break;
            case 0:
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid option, please enter again"<<endl;
        }
    }while(ch!=0);

    return 0;
}