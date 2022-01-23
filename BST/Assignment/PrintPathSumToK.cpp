#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;
/*
Input:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13
Output:
2 3 4 4 
2 3 8
*/
#include<string>
void printPathsSumToK(BinaryTreeNode<int> *root,int k,string track){
    if(root==NULL) return;
	if(root->data == k && !root->right && !root->left){
        cout<<track<<root->data<<endl;
    	//track = "";
	}
    printPathsSumToK(root->left,k-root->data,track+ to_string(root->data)+" ");
	printPathsSumToK(root->right,k-root->data,track+ to_string(root->data)+" ");
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    if(root==NULL) return;
    printPathsSumToK(root,k,"");
}
BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}