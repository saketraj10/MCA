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
class BST{
    private:
    TreeNode* root;
    public:
    BST(){
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
        if(node==NULL) return;
        cout<<node->val<<" ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void inorderTraversal(){
        inorderTraversal(root);
        cout<<endl;
    }

    void inorderTraversal(TreeNode* node){
        if(node==NULL) return;
        inorderTraversal(node->left);
        cout<<node->val<<" ";
        inorderTraversal(node->right);
    }

    void postorderTraversal(){
        postorderTraversal(root);
        cout<<endl;
    }

    void postorderTraversal(TreeNode* node){
        if(node==NULL) return;
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout<<node->val<<" ";
    }

    void search(int val){
        if(search(root, val)==NULL){
            cout<<val<<" is not found"<<endl;
        }
        else{
            cout<<val<<" is found"<<endl;
        }
    }

    TreeNode* search(TreeNode* node, int val){
        if(node==NULL || node->val==val) return node;
        if(node->val > val) return search(node->left, val);
        else return search(node->right, val);
    }
};
int main(){
    BST bst;
    bst.insert(100);
    bst.insert(20);
    bst.insert(200);
    bst.insert(10);
    bst.insert(30);
    bst.insert(150);
    bst.insert(300);

    bst.preorderTraversal();
    bst.inorderTraversal();
    bst.postorderTraversal();

    bst.search(10);
    bst.search(90);


    return 0;
}