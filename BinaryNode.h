#ifndef BINARYNODE_H
#define BINARYNODE_H
template <class H>
class BinaryNode {
    public:
        H element;
        BinaryNode<H>* left;
        BinaryNode<H>* right;
        BinaryNode (H e,BinaryNode<H>* l,BinaryNode<H>* r) {
            element=e;
            left=l;
            right=r;
        }
};
#endif /* BINARYNODE_H */

