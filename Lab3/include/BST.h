#ifndef BST_h
#define BST_h
class BST
{
    public:
        virtual bool isEmpty()=0;
        virtual void addBST(int value,int index)=0;
        virtual bool removeBST(int targetkey,int root)=0;
        virtual void searchBST(int targetkey)=0;
};
#endif