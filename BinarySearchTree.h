#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include "BinaryNode.h"

using namespace std;

template <class T>
class BinarySearchTree {    
    private:       
        BinaryNode<T>* m_root;    
        
        BinaryNode<T>* insert(T x,BinaryNode<T>* t) {
            if (t==NULL)
                t = new BinaryNode<T>(x,NULL,NULL);
            else if(x<t->element)
                t->left = insert(x,t->left);
            else if(x>t->element)
                t->right=insert(x,t->right); 
            return t;
        }
        void print(BinaryNode<T>* t) {
            if (t==NULL)
                return;
            print(t->left);            
            cout<<t->element<<",";            
            print(t->right);           
        }
        BinaryNode<T>* find(T x,BinaryNode<T>* t) {
            if (t == NULL)
                return NULL;  // elemento não está na árvore
            if (x<t->element)
                return find(x,t->left);
            else if( x>t->element)
                return find(x,t->right);
            else
                return t;    // encontrou
        }  
        T findMin(BinaryNode<T>* t) {
            if( t->left == NULL )
                return t->element;
            return findMin(t->left);
        }
        T findMax(BinaryNode<T>* t) {
            if( t->right == NULL )
                return t->element;
            return findMin(t->right);
        }  
        BinaryNode<T>* remove(int x,BinaryNode<T>* t) {
            if(t==NULL)
                return t;   // Item não está na árvore ou árvore vazia, não faça nada
            if( x<t->element)
                t->left = remove( x, t->left );
            else if( x>t->element)
                t->right = remove( x, t->right );
            else if( t->left!=NULL && t->right!=NULL) {  // Caso 3 – nó com dois filhos
                t->element = findMin(t->right);
                t->right = remove(t->element,t->right);
            }
            else {// Caso 1 e 2 – nó com um ou nenhum filho
                BinaryNode<T>* nodeToBeDeleted=t;
                t = (t->left!=NULL) ? t->left : t->right;
                delete nodeToBeDeleted;
            }
            return t;
        }        
    public:
        BinarySearchTree() {
            m_root=NULL;
        }
        bool isEmpty() {
            return (m_root==NULL);
        }
        void clear() {
            m_root=NULL;            
        }
        void insert(T x) {
            m_root=insert(x,m_root);  
        }
        void print() {
            if (isEmpty()) {
                cout<<"arvore Vazia"<<endl;
                return;
            }
            print(m_root);
            cout<<endl;
        }
        bool find(T x) {
            return find(x,m_root)!=NULL;   
        }
        T findMin() {
            if (isEmpty()) {
                throw "arvore Vazia";
            }
            return findMin(m_root);   
        }
        T findMax() {
            if (isEmpty()) {
                throw "arvore Vazia";
            }
            return findMax(m_root);     
        }
        void remove(T x) {
            m_root=remove(x,m_root);
        } 
 

};

#endif /* BINARYSEARCHTREE_H */
