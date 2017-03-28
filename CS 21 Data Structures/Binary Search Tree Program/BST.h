#ifndef BST_H
#define BST_H




class BSTNode{
    friend class BST;
    public:
    BSTNode(int item){
    data  = item;
    left = right = 0;
    }

protected:
int data;
BSTNode* left;
BSTNode* right;

};





class BST
{
    public:
        BST();
        ~BST();
        bool isEmpty();
        std::string printInOrderTraversal();
        std::string printPreOrderTraversal();
        std::string printPostOrderTraversal();
        void destroyThree();
        BSTNode* search(int item);
        BSTNode* insert(int key);
        bool delete_ (int key);
        BSTNode* min();
        BSTNode* max();
        BSTNode* successor(int key);
        BSTNode* predecessor(int key);
        int getInfo(BSTNode* p){return p->data;}


    private:
        BSTNode* root;
        void destroy(BSTNode* &p);
        void inOrder(BSTNode* p, std::stringstream& fout);
        void preOrder(BSTNode* p, std::stringstream& fout);
        void postOrder(BSTNode* p, std::stringstream& fout);
        void deleteNode(BSTNode* &p);
        BSTNode* searchNode(BSTNode* p, int key);
        BSTNode* findMin(BSTNode* p);
        BSTNode* findMax(BSTNode* p);
        BSTNode* findSuccessor(BSTNode* p, int key);
        BSTNode* findPredecessor(BSTNode* p, int key);


};

#endif // BST_H
