#include <string>
#include <iostream>

template <typename T>
struct no
{
    T key{};
    struct no *lf;
    struct no *rt;
};

template <typename K>
class Arvore
{
    no<K> *root;

public:
    Arvore() { root = NULL; }
    no<K>* binarySearch(K x, no<K> **pt, no<K> **pai)
    {
        if (!*pt)
            return *pai;
        else if (x == (*pt)->key)
        {
            return *pt;
        }
        else if (x < (*pt)->key)
        {
            if ((*pt)->lf)
                return binarySearch(x, &((*pt)->lf), pt);
            else
                return *pt;
        }
        else if (x > (*pt)->key)
        {
            if ((*pt)->rt)
                return binarySearch(x, &((*pt)->rt), pt);
            else
                return *pt;
        }
        return *pai;
    }
    void binaryInsert(K x)
    {
        if(!root){
            root = new no<K>;
            root->key = x;
            root->lf = NULL;
            root->rt = NULL;
        }
        no<K> *k = binarySearch(x, &root,&root);
        no<K> *pt1 = new no<K>;
        pt1->key = x;
        pt1->lf = NULL;
        pt1->rt = NULL;
        if(k->key > x){
            k->lf=pt1;
        }
        else if(k->key <x){
            k->rt = pt1;
        }
    }
    void printTree()
    {
        printTree("", root, false);
    }
    void printTree(const std::string &prefix, const no<K> *root, bool isLeft)
    {
        K f;
        if (root != nullptr && root->key != f)
        {
            std::cout << prefix;
            std::cout << (isLeft ? "├── " : "└── ");
            std::cout << root->key << std::endl;
            printTree(prefix + (isLeft ? "│   " : "    "), root->lf, true);
            printTree(prefix + (isLeft ? "│   " : "    "), root->rt, false);
        }
        else
        {
            std::cout << prefix;
            std::cout << (isLeft ? "├── " : "└── ");
            std::cout << "*" << std::endl;
        }
    }
};

int main()
{
    Arvore<int> p;
    p.binaryInsert(1);
    p.binaryInsert(2);
    p.binaryInsert(3);
    p.binaryInsert(4);
    p.binaryInsert(-1);
    p.printTree();
}