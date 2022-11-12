#include <iostream>
#include "tree.h"

#include <stdlib.h>
#include <time.h>


int main() {

    srand(time(NULL));
    Tree first_tree(5);
    for (int i = 1000; i > 0; i--) {
        first_tree.insert(rand() % 100);
    }
    /*
    Tree first_tree(5);
    first_tree.insert(0);
    first_tree.insert(4);
    first_tree.insert(11);
    first_tree.insert(19);*/
    Tree::iterator it1;
    it1 = first_tree.end();
    int i = 0;
    while (it1 != first_tree.begin()) {
        std::cout << *it1 << std::endl;
        it1--;
        i++;
    }
    std::cout << *it1 << std::endl;
    return 0;
}
