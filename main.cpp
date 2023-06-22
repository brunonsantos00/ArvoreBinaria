#include <cstdlib>
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;


int main(int argc, char** argv) { 
    
 
    BinarySearchTree <int> bst; 
      
    
    int vazio = bst.isEmpty();
    cout << "Esta vazio:" << vazio << endl;
    bst.insert(8);
    bst.print();
    bst.insert(7);
	bst.print();   
	bst.findMin();
	bst.findMax();
	bst.remove(8);
	bst.print();
	bst.remove(7);
	bst.print();
	bst.clear();
	
	

    
}

 
